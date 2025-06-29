//
// Created by Jonathan Lampérth on 20.05.21.
//

#include "headers/keynote.h"
#include "proto_helper.h"
#include "src/svg_to_key/svg_to_key.h"
#include "src/key_to_svg/key_to_svg.h"
#include <iostream>


std::string decodeAndEncode(std::string protobufString) {
    std::vector<MessageWrapper*> objects = convertProtobufToListOfMesssages(protobufString);
    return convertListOfMessagesToProtoStream(objects);
}

std::string generateTSPNativeDataClipboardFromSVG(std::string svgData) {
    std::vector<MessageWrapper *> objects = convertSVGFileToKeynoteClipboard(svgData); // Assign returned vector directly
    return convertListOfMessagesToProtoStream(objects);
}
std::string generateTSPNativeMetadataClipboard() {
    auto metadataMessageList = generateMetadataMessageList();
    return convertListOfMessagesToProtoStream(metadataMessageList);
}

std::string generateSVGFromKeynoteIWAFiles(const std::vector<keynoteIWAFile>& entries) {
    return convertVectorOfIWAFilesToSVG(entries);
}

