//
// Created by Jonathan Lampérth on 19.05.21.
//

#ifndef KEYNOTE_PROTO_HELPER_H
#define KEYNOTE_PROTO_HELPER_H


#include <KNCommandArchives.pb.h>
//#include <TNArchives.pb.h>
//#include <TNArchives.sos.pb.h>
//#include <TNCommandArchives.pb.h>
//#include <TPArchives.pb.h>
//#include <TPCommandArchives.pb.h>
#include <TSAArchives.pb.h>
#include <TSCEArchives.pb.h>
#include <TSCH3DArchives.pb.h>
#include <TSCHArchives.Common.pb.h>
#include <TSCHArchives.GEN.pb.h>
#include <TSCHArchives.pb.h>
#include <TSCHCommandArchives.pb.h>
#include <TSCHPreUFFArchives.pb.h>
#include <TSDArchives.pb.h>
#include <TSDCommandArchives.pb.h>
#include <TSKArchives.pb.h>
#include <TSPArchiveMessages.pb.h>
#include <TSPDatabaseMessages.pb.h>
#include <TSPMessages.pb.h>
#include <TSSArchives.pb.h>
#include <TSTArchives.pb.h>
#include <TSTCommandArchives.pb.h>
#include <TSTStylePropertyArchiving.pb.h>
#include <TSWPArchives.pb.h>
#include <TSWPCommandArchives.pb.h>
#include <KNArchives.sos.pb.h>
#include <TSAArchives.sos.pb.h>
#include <TSCHArchives.pb.h>
#include <TSKArchives.sos.pb.h>
#include <TSACommandArchives.sos.pb.h>
#include <TSCHPreUFFArchives.pb.h>
#include <KNArchives.sos.pb.h>
#include <KNCommandArchives.sos.pb.h>
//#include <TPCommandArchives.sos.pb.h>
//#include <TNArchives.sos.pb.h>
//#include <TNCommandArchives.sos.pb.h>
#include <nanosvg.h>


struct MessageWrapper
{
    uint64_t identifier;
    uint32_t type;
    google::protobuf::Message *message;
    TSP::ArchiveInfo *archiveInfo;
};

TSP::ArchiveInfo* getArchiveInfoFromStream(google::protobuf::io::CodedInputStream &stream);

std::vector<MessageWrapper*> convertProtobufToListOfMesssages(std::string input_string);

std::string convertListOfMessagesToProtoStream(std::vector<MessageWrapper *> vector);



std::vector<MessageWrapper*> generateMetadataMessageList();

MessageWrapper * createMessageWrapper(google::protobuf::Message* message, google::protobuf::uint32 type, google::protobuf::uint64 identifier);

static void nsvg__xformInverse(float* inv, float* t);

static void nsvg__xformIdentity(float* t);

#endif //KEYNOTE_PROTO_HELPER_H