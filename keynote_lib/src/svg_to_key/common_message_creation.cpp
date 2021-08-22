//
// Created by Jonathan Lampérth on 25.07.21.
//

#include <TSDArchives.pb.h>
#include "common_message_creation.h"

TSP::Point* createPoint(float x, float y) {
    auto* point = new TSP::Point();
    point->set_x(x);
    point->set_y(y);
    return point;
}


TSP::Point* setPoint(TSP::Point *point, float x, float y) {
    point->set_x(x);
    point->set_y(y);
    return point;
}


TSP::Size *createSize(float width, float height) {
    auto* size = new TSP::Size();
    size->set_width(width);
    size->set_height(height);
    return size;
}

TSD::GeometryArchive* createGeometryArchive(float width, float height, float x, float y, float angle) {
    auto* tsdGeometryArchive = new TSD::GeometryArchive();
    tsdGeometryArchive->set_allocated_size(createSize(width, height));
    tsdGeometryArchive->set_allocated_position(createPoint(x,y));
    // todo: note here why we set flag to be 3, has to do with it being a shape and not a text box iirc
    tsdGeometryArchive->set_flags(3);
    tsdGeometryArchive->set_angle(angle);
    return tsdGeometryArchive;
}

void addPathElement(TSP::Path* path, float x, float y, TSP::Path_ElementType type) {
    TSP::Path_Element* element =  path->add_elements();
    element->set_type(type);
    setPoint(element->add_points(), x, y);
}

void addBezierPathElement(TSP::Path* path, float x_in, float y_in, float x_control, float y_control, float x_out, float y_out) {
    TSP::Path_Element* element =  path->add_elements();
    element->set_type(TSP::Path_ElementType_curveTo);

    setPoint(element->add_points(), x_in, y_in);
    setPoint(element->add_points(), x_control, y_control);
    setPoint(element->add_points(), x_out, y_out);
}

// expects RGBA Values \in [0, 255]

TSP::Color *createColor(float r, float g, float b, float a) {
    auto* color = new TSP::Color();
    color->set_r(r / 255);
    color->set_g(g / 255);
    color->set_b(b / 255);
    color->set_a(a / 255);
    color->set_model(TSP::Color_ColorModel_rgb);
    color->set_rgbspace(TSP::Color_RGBColorSpace_srgb);
    return color;
}
