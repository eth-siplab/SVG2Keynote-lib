//
// Created by Jonathan Lampérth on 15.05.21.
//

#include "ShapeObject.h"
#include "../../../keynote-protos/mapping/ProtoMapping.h"
#include <sstream>


ShapeObject::ShapeObject(google::protobuf::Message& message) : SlideObject(message) {
    if (message.GetTypeName() == "TSWP.ShapeInfoArchive") {
        TSWP::ShapeInfoArchive shapeInfo = dynamic_cast<TSWP::ShapeInfoArchive &>(message);
        x = shapeInfo.super().super().geometry().position().x();
        y = shapeInfo.super().super().geometry().position().y();
        height = shapeInfo.super().super().geometry().size().height();
        width = shapeInfo.super().super().geometry().size().width();
    }
}

std::string ShapeObject::getSVG() {
    std::stringstream pathstring;
    auto shapeInfo = dynamic_cast<TSWP::ShapeInfoArchive &>(message);
    auto x = shapeInfo.super().super().geometry().position().x();
    auto y = shapeInfo.super().super().geometry().position().y();
    auto height = shapeInfo.super().super().geometry().size().height();
    auto width = shapeInfo.super().super().geometry().size().width();
    pathstring << "<svg "<< "x=\"" << x << "px\" y=\"" << y << "px\" " << "width=\"" << width << "px\"" << " height=\"" << height <<  "px\" " << "viewBox=\"0 0 100 100\"" << ">" << std::endl;


    if (shapeInfo.has_super()) {
        TSD::ShapeArchive shapeArchive = shapeInfo.super();
        if (shapeArchive.has_pathsource()) {
            TSD::PathSourceArchive pathSourceArchive = shapeArchive.pathsource();
            if (pathSourceArchive.has_bezier_path_source()) {
                TSD::BezierPathSourceArchive bezier = pathSourceArchive.bezier_path_source();
                if (bezier.has_path()) {
                    TSP::Path path = bezier.path();
                    pathstring << "<path d=\"";
                    // todo: figure out nested svgs for relative location later
                    for (const auto &item : path.elements()) {
                        if (item.type() == TSP::Path_ElementType_moveTo) {
                            // todo: are there cases when item has more than one point ???
                            pathstring << "M ";
                            for (const auto &point : item.points()) {
                                pathstring << point.x() << " " << point.y() << " ";
                            }
                        }

                        if (item.type() == TSP::Path_ElementType_lineTo) {
                            // todo: are there cases when item has more than one point ???
                            pathstring << "L ";
                            for (const auto &point : item.points()) {
                                pathstring << point.x() << " " << point.y() << " ";
                            }
                        }

                        if (item.type() == TSP::Path_ElementType_curveTo) {
                            // curveTo has 3 points
                            pathstring << "C ";
                            auto pointA = item.points().Get(0);
                            auto pointB = item.points().Get(1);
                            auto pointC = item.points().Get(2);

                            pathstring << pointA.x() << " " << pointA.y() << ", ";
                            pathstring << pointB.x() << " " << pointB.y() << ", ";
                            pathstring << pointC.x() << " " << pointC.y() << " ";

                        }
                    }
                    pathstring << R"(" stroke="blue" fill="green" />)" << std::endl;
                } else {

                }
            } else {
                // no bezier path (unhandled for now)
                pathstring << "<rect height=\"" << height << "\" width=\"" << width << "\" />" << std::endl;
            }
        }
    }
    pathstring << "</svg>";
    return pathstring.str();
}