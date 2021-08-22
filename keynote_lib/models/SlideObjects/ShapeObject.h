//
// Created by Jonathan Lampérth on 15.05.21.
//

#ifndef KEYNOTE_SHAPEOBJECT_H
#define KEYNOTE_SHAPEOBJECT_H


#include "SlideObject.h"
#include <google/protobuf/message.h>



class ShapeObject : public SlideObject {
public:
    explicit ShapeObject(google::protobuf::Message &message);
private:
    float x;
    float y;
    float height;
    float width;
    std::string getSVG();
};


#endif //KEYNOTE_SHAPEOBJECT_H
