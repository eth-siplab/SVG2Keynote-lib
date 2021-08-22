//
// Created by Jonathan Lampérth on 22.08.21.
//

#include "shape_creation_repository.h"
#include "nanosvg_helper.h"
#include "common_message_creation.h"


MessageWrapper *createCustomBezierShapeInfoArchive(google::protobuf::uint64 identifier, google::protobuf::uint64 styleIdentifier, TSD::BezierPathSourceArchive* bezierPathSourceArchive, float height, float width, float x, float y) {

    auto*  tswpShapeInfoArchive = new TSWP::ShapeInfoArchive;

    // requires only super
    auto*  tsdShapeArchive = new TSD::ShapeArchive;

    // optional .TSD.GeometryArchive geometry = 1;
    auto* tsdDrawableArchive = new TSD::DrawableArchive;

    auto * tsdGeometryArchive = new TSD::GeometryArchive;

    auto * tsdShapeStyle = new TSP::Reference;
    tsdShapeStyle->set_identifier(styleIdentifier);
    // requires nothing we will add optional TSD::BezierPathSourceArchive
    auto* tsdPathSourceArchive = new TSD::PathSourceArchive;

//    auto* tsdBezierPathSourceArchive = bezier

    tsdPathSourceArchive->set_allocated_bezier_path_source(bezierPathSourceArchive);
    tsdPathSourceArchive->set_horizontalflip(false);
    tsdPathSourceArchive->set_verticalflip(false);

    tsdShapeArchive->set_allocated_super(tsdDrawableArchive);
    tsdShapeArchive->set_allocated_pathsource(tsdPathSourceArchive);
    tsdShapeArchive->set_allocated_style(tsdShapeStyle);
    tsdShapeArchive->set_strokepatternoffsetdistance(0);

    auto* tspSize = createSize(width, height);
    auto* tspPosition = createPoint(x,y);


    tsdGeometryArchive->set_allocated_size(tspSize);
    tsdGeometryArchive->set_allocated_position(tspPosition);


    tsdDrawableArchive->set_allocated_geometry(tsdGeometryArchive);
    // style is optional in defintion. Ignore for time being if no bugs encountered.
    // tsdShapeArchive->set_allocated_style()
    tswpShapeInfoArchive->set_allocated_super(tsdShapeArchive);

    return createMessageWrapper(tswpShapeInfoArchive, 2011, identifier);
}




MessageWrapper* createShapeStyleArchiveWrapper(google::protobuf::uint64 styleIdentifier, NSVGshape* shape) {
    auto* styleArchive = new TSS::StyleArchive();
    styleArchive->set_allocated_style_identifier(new std::string("shape-0-shapestyle"));

    auto* fillArchive = new TSD::FillArchive();
    handleNanoSVGFill(fillArchive, shape);

    auto* strokeArchive = new TSD::StrokeArchive();
    handleNanoSVGStroke(strokeArchive, shape);

    auto* shapeStylePropertiesArchive = new TSD::ShapeStylePropertiesArchive();

    if (shape->fill.type != NSVG_PAINT_NONE) {
        shapeStylePropertiesArchive->set_allocated_fill(fillArchive);
    }

    if (shape->stroke.type != NSVG_PAINT_NONE) {
        shapeStylePropertiesArchive->set_allocated_stroke(strokeArchive);
    }

    shapeStylePropertiesArchive->set_opacity(shape->opacity);

    auto * tsdShapeStyleArchive = new TSD::ShapeStyleArchive();
    tsdShapeStyleArchive->set_allocated_shape_properties(shapeStylePropertiesArchive);
    tsdShapeStyleArchive->set_allocated_super(styleArchive);
    tsdShapeStyleArchive->set_override_count(1000);

    // This is the top level shapeStyleArchive
    auto* tswpShapeStyleArchive = new TSWP::ShapeStyleArchive();

    // set super to TSD::ShapeStyleArchive
    tswpShapeStyleArchive->set_allocated_super(tsdShapeStyleArchive);
    return createMessageWrapper(tswpShapeStyleArchive, 2025, styleIdentifier);
}