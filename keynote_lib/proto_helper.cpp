//
// Created by Jonathan Lampérth on 27.04.21.
//
//#include "IWMessageTypeRegistry.h"


#include "../keynote-protos/mapping/ProtoMapping.h"
#include <google/protobuf/message.h>
#include "proto_helper.h"
#include "src/svg_to_key/svg_to_key.h"
#include "src/svg_to_key/common_message_creation.h"
#include "src/svg_to_key/nanosvg_helper.h"
#include <sstream>
#include <algorithm>
#include <random>
#include <nanosvg.h>

TSP::ArchiveInfo* getArchiveInfoFromStream(google::protobuf::io::CodedInputStream &stream) {
    google::protobuf::uint64 size;
    stream.ReadVarint64(&size);
    auto* archiveInfo = new TSP::ArchiveInfo();
    // Limit amount of bytes allowed to be consumed, so ParseFromCodedStream only consumes the archiveInfo data from the stream
    google::protobuf::io::CodedInputStream::Limit limit = stream.PushLimit((int)size);
    if (!archiveInfo->ParseFromCodedStream(&stream)) {
        std::cout << "Could not Parse TSP::ArchiveInfo" << std::endl;
    }
    stream.PopLimit(limit);
    return archiveInfo;
}



std::vector<MessageWrapper*> convertProtobufToListOfMesssages(std::string input_string) {
    std::vector<google::protobuf::Message*> arr;
    std::vector<MessageWrapper*> new_arr;
    google::protobuf::io::CodedInputStream stream((const google::protobuf::uint8 *) &input_string[0], (int) input_string.length());
    while (stream.BytesUntilLimit() > 0) {
        TSP::ArchiveInfo* archiveInfo = getArchiveInfoFromStream(stream);
        uint64_t identifier = archiveInfo->identifier();
        std::string file_type = "keynote";
        ProtoMapping map(file_type);

        // For each TSP::MessageInfo in TSP::ArchiveInfo (should only be one) decode the data
        for (const TSP::MessageInfo &messageInfo : archiveInfo->message_infos()) {
            const google::protobuf::Message *messagePrototype = map._messageTypeToPrototypeMap[messageInfo.type()];
            if (messagePrototype == nullptr) {
                std::cerr << "Unknown message type: " << messageInfo.type() << std::endl;
                stream.Skip(messageInfo.length());
                continue;
            }

            google::protobuf::io::CodedInputStream::Limit limit = stream.PushLimit((int) messageInfo.length());
            {
                google::protobuf::Message *message = messagePrototype->New();
                if (!message->ParseFromCodedStream(&stream)) {
                    delete message;
                    std::cerr << "Could not parse coded stream" << std::endl;
                    break;
                }

                auto* messageWrapper = new MessageWrapper{identifier, messageInfo.type(),message, archiveInfo};
                new_arr.push_back(messageWrapper);
            }
            stream.PopLimit(limit);
        }
    }
    return new_arr;
}


std::string convertListOfMessagesToProtoStream(std::vector<MessageWrapper *> vector) {
    std::stringstream outPut;

    for (auto message : vector) {
        // makes sure the correct length is set if we make changes to message contents after initialization
        message->archiveInfo->mutable_message_infos(0)->set_length(message->message->SerializeAsString().length());

        std::string archiveInfoString = message->archiveInfo->SerializeAsString();
        std::string messageString = message->message->SerializeAsString();
        google::protobuf::uint64 size = archiveInfoString.length();
        size_t varIntSize = google::protobuf::io::CodedOutputStream::VarintSize64(size);
        auto * varIntArr = new google::protobuf::uint8[varIntSize];
        google::protobuf::io::CodedOutputStream::WriteVarint64ToArray(size, varIntArr);
        outPut.write(reinterpret_cast<const char *>(varIntArr), varIntSize);
        outPut << archiveInfoString;
        outPut << messageString;
        delete[] varIntArr;
    }
    return outPut.str();
}

std::vector<MessageWrapper *> generateMetadataMessageList() {
    // generate TSP.PasteboardMetadata
    auto* pasteboardMetadata = new TSP::PasteboardMetadata();
    pasteboardMetadata->add_version(11);
    pasteboardMetadata->add_version(1);
    pasteboardMetadata->add_version(2);
    pasteboardMetadata->set_allocated_app_name(new std::string("com.apple.Keynote 11.1"));
    pasteboardMetadata->add_read_version(2);
    pasteboardMetadata->add_read_version(0);
    pasteboardMetadata->add_read_version(0);

    return std::vector<MessageWrapper *> {createMessageWrapper(pasteboardMetadata, 11007, 52)};
}





MessageWrapper *createMessageWrapper(google::protobuf::Message *message, google::protobuf::uint32 type,
                                     google::protobuf::uint64 identifier) {
    auto* messageWrapper = new MessageWrapper();

    auto* archiveInfo =  new TSP::ArchiveInfo();
    auto* messageInfo = archiveInfo->add_message_infos();
    messageInfo->set_type(type);
    messageInfo->set_length(message->SerializeAsString().length());

    archiveInfo->set_identifier(identifier);

    messageWrapper->archiveInfo = archiveInfo;
    messageWrapper->identifier = identifier;
    messageWrapper->message = message;

    return messageWrapper;
}