//
// Created by Jonathan Lampérth on 19.05.21.
//

#include "snappy_helper.h"
#include <vector>
#include <boost/endian/conversion.hpp>
#include <snappy.h>
#include <iostream>




std::string processSnappyStream(char* char_array, unsigned long n) {
    std::string iwaSnappyUncompressed;
    unsigned long counter = 0;
    while (counter + 4 < n) {
        iwaSnappyUncompressed.append(processIWAFilePart(&char_array[counter], counter));
    }
    return iwaSnappyUncompressed;
}

std::string processIWAFile(std::vector<unsigned char> entry) {
    std::string string_unsigned(entry.begin(), entry.end());
    unsigned long n = string_unsigned.length();
    char* char_array = new char[n];
    std::memcpy(char_array, string_unsigned.c_str(), n);
    return processSnappyStream(char_array, n);
}


std::string processIWAFilePart(char *char_array, unsigned long &counter) {
    uint32_t chunkLength = boost::endian::load_little_s24((unsigned char*) &char_array[1]);
    counter = counter + chunkLength + 4;

    std::string output;
    if (!snappy::IsValidCompressedBuffer(&char_array[4], chunkLength)) {
        std::cerr << "Stream is not a compatible snappy stream :(" << std::endl;
    }

    snappy::Uncompress(&char_array[4], chunkLength, &output);
    return output;
}
