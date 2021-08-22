//
// Created by Jonathan Lampérth on 15.05.21.
//

#include <google/protobuf/message.h>
#include <google/protobuf/any.h>
#include "SlideObjectFactory.h"
#include "ShapeObject.h"


SlideObject * SlideObjectFactory::GetSlideObject(int messageType, google::protobuf::Message &message) {
    switch (messageType) {
        // TSWP::ShapeInfoArchive()
        case 2011:
            return new ShapeObject(message);
        default:
            return new SlideObject(message);
    }
}
