//
// Created by Jonathan Lampérth on 19.05.21.
//
#ifndef KEYNOTE_SNAPPY_HELPER_H

#define KEYNOTE_SNAPPY_HELPER_H
#include<string>

std::string processIWAFile(std::vector<unsigned char> entry);
std::string processIWAFilePart(char* char_array, unsigned long &counter);


#endif //KEYNOTE_SNAPPY_HELPER_H
