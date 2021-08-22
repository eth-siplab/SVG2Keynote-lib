//
// Created by Jonathan Lampérth on 15.05.21.
//

#include <google/protobuf/message.h>
#include "BaseObject.h"

// todo: is this kosher? or should message not be a reference and in the constructor call BaseObject::message.CopyFrom(message)??
BaseObject::BaseObject(google::protobuf::Message &message) : message(message) {
    debug_string = message.DebugString();
}

std::string BaseObject::getSVG() {
    return std::string();
}
