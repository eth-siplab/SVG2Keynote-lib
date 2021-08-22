//
// Created by Jonathan Lampérth on 25.07.21.
//

#include <TSDArchives.pb.h>
#include <nanosvg.h>
#include "nanosvg_helper.h"
#include "../../proto_helper.h"
#include "svg_to_key.h"
#include "common_message_creation.h"



void handleNanoSVGFill(TSD::FillArchive *fillArchive, NSVGshape *shape) {
    std::tuple<unsigned int, unsigned int, unsigned int, unsigned int> fillColorTuple = {0, 0, 0, 0};
    if (shape->fill.type == NSVG_PAINT_COLOR) { fillColorTuple = convertColorToRGB(shape->fill.color); }

    auto* fillColor = createColor((float)std::get<0>(fillColorTuple), (float)std::get<1>(fillColorTuple), (float)std::get<2>(fillColorTuple), (float)std::get<3>(fillColorTuple));

    if (shape->fill.type == NSVG_PAINT_LINEAR_GRADIENT) {
        auto stops = shape->fill.gradient->nstops;
        auto* gradientArchive = new TSD::GradientArchive;
        gradientArchive->set_type(TSD::GradientArchive_GradientType_Linear);
        gradientArchive->set_advancedgradient(true);
        gradientArchive->set_opacity(1);


        // create inverse of gradient xform
        float inv[6];
        memcpy(inv, shape->fill.gradient->xform, sizeof(float)*6);
        nsvg__xformInverse(inv, shape->fill.gradient->xform);
        std::cout << "x1: " << inv[4] << std::endl;

        auto dx = inv[2];
        auto dy = inv[3];

        auto x1 = inv[4];
        auto y1 = inv[5];

        auto x2 = dx + x1;
        auto y2 = dy + y1;

        auto [width, height, x, y] = getWidthHeightXY(shape->bounds);

        auto* size = createSize(width, height);
        auto* begin = createPoint(x1, y1);
        auto* end = createPoint(x2, y2);

        auto* transformGradientArchive = new TSD::TransformGradientArchive();
        transformGradientArchive->set_allocated_basenaturalsize(size);
        transformGradientArchive->set_allocated_start(begin);
        transformGradientArchive->set_allocated_end(end);

        gradientArchive->set_allocated_transformgradient(transformGradientArchive);
        for (int i = 0; i < stops; i++) {
            auto [r, g, b, a] = convertColorToRGB(shape->fill.gradient->stops[i].color);
            auto* stopColor = new TSP::Color();
            stopColor->set_r(((float)r)/255);
            stopColor->set_g(((float)g)/255);
            stopColor->set_b(((float)b)/255);
            stopColor->set_a(((float)a)/255);
            stopColor->set_model(TSP::Color_ColorModel_rgb);
            stopColor->set_rgbspace(TSP::Color_RGBColorSpace_srgb);

            auto* currentStop = gradientArchive->add_stops();
            currentStop->set_fraction(shape->fill.gradient->stops[i].offset);
            currentStop->set_inflection(0.5);
            currentStop->set_allocated_color(stopColor);
        }
        fillArchive->set_allocated_gradient(gradientArchive);
    }

    if (shape->fill.type == NSVG_PAINT_COLOR) {
        fillArchive->set_allocated_color(fillColor);
    }

    if (shape->fill.type == NSVG_PAINT_RADIAL_GRADIENT) {
        auto [r, g, b, a] = convertColorToRGB(shape->fill.gradient->stops[0].color);
        auto* gradientFillColor = new TSP::Color();
        gradientFillColor->set_r(((float)r)/255);
        gradientFillColor->set_g(((float)g)/255);
        gradientFillColor->set_b(((float)b)/255);
        gradientFillColor->set_a(1.0f);
        gradientFillColor->set_model(TSP::Color_ColorModel_rgb);
        gradientFillColor->set_rgbspace(TSP::Color_RGBColorSpace_srgb);
        fillArchive->set_allocated_color(gradientFillColor);
    }
}


void handleNanoSVGStroke(TSD::StrokeArchive *strokeArchive, NSVGshape *shape) {
    if (shape->stroke.type == NSVG_PAINT_COLOR) {
        auto strokeColorTuple = convertColorToRGB(shape->stroke.color);
        auto* strokeColor = createColor((float)std::get<0>(strokeColorTuple), (float)std::get<1>(strokeColorTuple), (float)std::get<2>(strokeColorTuple), (float)std::get<3>(strokeColorTuple));
        strokeArchive->set_allocated_color(strokeColor);
    }

    strokeArchive->set_width(shape->strokeWidth);
    setLineCap(strokeArchive, shape->strokeLineCap);
    setLineJoin(strokeArchive, shape->strokeLineJoin, shape->miterLimit);

    // warning: this may not function as intended, due to how Keynote handles stroke patterns.
    // Keynote seems to require, that there is at least one dash as wide as the width of the stroke.
    setStrokePattern(strokeArchive, shape);
}

void setStrokePattern(TSD::StrokeArchive *strokeArchive, NSVGshape *shape) {
    if ((int) shape->strokeDashCount != 0) {
        auto* strokePatternArchive = new TSD::StrokePatternArchive();
        strokePatternArchive->set_type(TSD::StrokePatternArchive_StrokePatternType_TSDPattern);
        strokePatternArchive->set_count((int) shape->strokeDashCount);
        strokePatternArchive->set_phase(0);
        for (int i = 0; i < (int) shape->strokeDashCount; i++) {
            strokePatternArchive->add_pattern(shape->strokeDashArray[i]);
        }
        strokeArchive->set_allocated_pattern(strokePatternArchive);
    }
}

void setLineJoin(TSD::StrokeArchive *strokeArchive, char joinIdentifier, float miterLimit) {
    switch(joinIdentifier) {
        case NSVG_JOIN_MITER:
            strokeArchive->set_join(TSD::MiterJoin);
            strokeArchive->set_miter_limit(miterLimit);
            break;
        case NSVG_JOIN_ROUND:
            strokeArchive->set_join(TSD::RoundJoin);
            break;
        case NSVG_JOIN_BEVEL:
            strokeArchive->set_join(TSD::BevelJoin);
            break;
        default:
            strokeArchive->set_join(TSD::MiterJoin);
            strokeArchive->set_miter_limit(miterLimit);
            break;
    }
}

void setLineCap(TSD::StrokeArchive *strokeArchive, char capIdentifier) {
    switch (capIdentifier) {
        case NSVG_CAP_BUTT:
            strokeArchive->set_cap(TSD::StrokeArchive_LineCap_ButtCap);
            break;
        case NSVG_CAP_ROUND:
            strokeArchive->set_cap(TSD::StrokeArchive_LineCap_RoundCap);
            break;
        case NSVG_CAP_SQUARE:
            strokeArchive->set_cap(TSD::StrokeArchive_LineCap_SquareCap);
            break;
        default:
            strokeArchive->set_cap(TSD::StrokeArchive_LineCap_ButtCap);
            break;
    }
}

std::tuple<float, float, float, float> getWidthHeightXY(float *bounds) {
    // convert array to bound variables
    float min_x = bounds[0]; float min_y = bounds[1]; float max_x = bounds[2]; float max_y = bounds[3];

    // calculate size of bounding box
    float width = max_x - min_x;
    float height = max_y - min_y;

    // in keynote position is defined by topleft of bounding box
    float x = min_x;
    float y = min_y;
    return {width, height, x, y};
}


// function taken from nanosvg.h, because it is not publicly accessible
static void nsvg__xformInverse(float* inv, float* t)
{
    double invdet, det = (double)t[0] * t[3] - (double)t[2] * t[1];
    if (det > -1e-6 && det < 1e-6) {
        nsvg__xformIdentity(t);
        return;
    }
    invdet = 1.0 / det;
    inv[0] = (float)(t[3] * invdet);
    inv[2] = (float)(-t[2] * invdet);
    inv[4] = (float)(((double)t[2] * t[5] - (double)t[3] * t[4]) * invdet);
    inv[1] = (float)(-t[1] * invdet);
    inv[3] = (float)(t[0] * invdet);
    inv[5] = (float)(((double)t[1] * t[4] - (double)t[0] * t[5]) * invdet);
}
// function taken from nanosvg.h, because it is not publicly accessible
static void nsvg__xformIdentity(float* t)
{
    t[0] = 1.0f; t[1] = 0.0f;
    t[2] = 0.0f; t[3] = 1.0f;
    t[4] = 0.0f; t[5] = 0.0f;
}
