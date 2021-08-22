//
// Created by Jonathan Lampérth on 25.07.21.
//

#include <TSPMessages.pb.h>

#ifndef KEYNOTE_COMMON_MESSAGE_CREATION_H
#define KEYNOTE_COMMON_MESSAGE_CREATION_H

TSP::Point* createPoint(float x, float y);
TSP::Point* setPoint(TSP::Point* point, float x, float y);
TSP::Size* createSize(float width, float height);
TSD::GeometryArchive* createGeometryArchive(float width, float height, float x, float y, float angle = 0);
void addPathElement(TSP::Path* path, float x, float y, TSP::Path_ElementType type);
void addBezierPathElement(TSP::Path* path, float x_in, float y_in, float x_control, float y_control, float x_out, float y_out);
TSP::Color* createColor(float r, float g, float b, float a = 255);


#endif //KEYNOTE_COMMON_MESSAGE_CREATION_H

