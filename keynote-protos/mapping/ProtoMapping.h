//
// Created by Jonathan Lampérth on 29.04.21.
//

#ifndef KEYNOTE_PROTOMAPPING_H
#define KEYNOTE_PROTOMAPPING_H

#include <KNArchives.pb.h>
#include <KNCommandArchives.pb.h>
#include <KNCommandArchives.sos.pb.h>
#include <TSKArchives.sos.pb.h>
#include <TSCHCommandArchives.pb.h>
#include <TSTCommandArchives.pb.h>
#include <TSPArchiveMessages.pb.h>
#include <map>
#include <google/protobuf/message.h>

class ProtoMapping {
public:
    explicit ProtoMapping(std::string type);
    std::map<google::protobuf::uint32, const google::protobuf::Message *> _messageTypeToPrototypeMap;

private:
    void registerKeynoteMessageTypes();
    void registerCommonMessageTypes();
};


#endif //KEYNOTE_PROTOMAPPING_H
