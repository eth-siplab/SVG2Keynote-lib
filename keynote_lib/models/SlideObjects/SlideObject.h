//
// Created by Jonathan Lampérth on 15.05.21.
//
#include <google/protobuf/any.h>
#include "BaseObject.h"

#ifndef KEYNOTE_SLIDEOBJECT_H
#define KEYNOTE_SLIDEOBJECT_H


class SlideObject : public BaseObject {
public:
    explicit SlideObject(google::protobuf::Message& message);
};


#endif //KEYNOTE_SLIDEOBJECT_H
