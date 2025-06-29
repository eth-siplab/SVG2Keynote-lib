//
// Created by Jonathan Lampérth on 22.06.21.
//

#ifndef KEYNOTE_SVG_TO_KEY_H
#define KEYNOTE_SVG_TO_KEY_H
#include<string>
#include<iostream>
#include "../../proto_helper.h"

std::vector<MessageWrapper *>* createInitialClipboardMessages(google::protobuf::uint64 pasteboardNativeStorageArchiveIdentifier, google::protobuf::uint64 pasteboardObjectIdentifier, google::protobuf::uint64 stylesheetIdentifier);
void initializeNode(TSD::EditableBezierPathSourceArchive_Node * node, float inX, float inY, float nodeX, float nodeY, float outX, float outY);
MessageWrapper* createShapeInfoArchive(TSD::EditableBezierPathSourceArchive *editableBezierPathSourceArchive,float width, float height, float x, float y, google::protobuf::uint64 styleIdentifier, google::protobuf::uint64 identifier);
MessageWrapper* createPasteboardNativeStorageArchiveMessageWrapper(google::protobuf::uint64 identifier);
MessageWrapper* createPasteboardObjectMessageWrapper(google::protobuf::uint64 identifier, google::protobuf::uint64 appNativeObjectIdentifier, google::protobuf::uint64 stylesheetIdentifier);
void addDrawableReferenceToPasteboard(std::vector<MessageWrapper *>* vector, google::protobuf::uint64 identifier, float x, float y, float width, float height);
std::tuple<unsigned int, unsigned int, unsigned int, unsigned int> convertColorToRGB(unsigned int color);
std::vector<MessageWrapper *> convertSVGFileToKeynoteClipboard(std::string fileContents); // Changed to return by value
void addStyleReferenceToStylesheet(google::protobuf::uint64 identifier, std::vector<MessageWrapper *> *pVector);


#endif //KEYNOTE_SVG_TO_KEY_H
