//
// Created by Jonathan Lampérth on 20.05.21.
//

#ifndef KEYNOTE_KEYNOTE_H
#define KEYNOTE_KEYNOTE_H

#include<iostream>
#include <vector>

struct keynoteIWAFile {
    std::string name;
    std::vector<unsigned char> contents;
};

std::string decodeAndEncode(std::string protobufString);
// std::string decodeAddSquareDecode(std::string protobufString); // Removed, not implemented and only used in _disabled code
std::string generateTSPNativeDataClipboardFromSVG(std::string svgData);
std::string generateTSPNativeMetadataClipboard();
std::string generateSVGFromKeynoteIWAFiles(const std::vector<keynoteIWAFile>& entries);




#endif //KEYNOTE_KEYNOTE_H


