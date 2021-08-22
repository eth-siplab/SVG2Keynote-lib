//
// Created by Jonathan Lampérth on 15.05.21.
//

#ifndef KEYNOTE_BASEOBJECT_H
#define KEYNOTE_BASEOBJECT_H


class BaseObject {
public:
    explicit BaseObject(google::protobuf::Message& message);
    std::string debug_string;
    google::protobuf::Message& message;
    virtual std::string getSVG();
};


#endif //KEYNOTE_BASEOBJECT_H
