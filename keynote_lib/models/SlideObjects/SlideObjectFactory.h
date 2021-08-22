//
// Created by Jonathan Lampérth on 15.05.21.
//

#ifndef KEYNOTE_SLIDEOBJECTFACTORY_H
#define KEYNOTE_SLIDEOBJECTFACTORY_H


#include "SlideObject.h"

class SlideObjectFactory {
public:
    static SlideObject * GetSlideObject(int messageType, google::protobuf::Message& message);
};


#endif //KEYNOTE_SLIDEOBJECTFACTORY_H
