//
// Created by Jonathan Lampérth on 22.08.21.
//

#ifndef KEYNOTE_SHAPE_CREATION_REPOSITORY_H
#define KEYNOTE_SHAPE_CREATION_REPOSITORY_H

#include <google/protobuf/stubs/port.h>
#include "../../proto_helper.h"

MessageWrapper *createCustomBezierShapeInfoArchive(google::protobuf::uint64 identifier, google::protobuf::uint64 styleIdentifier, TSD::BezierPathSourceArchive* bezierPathSourceArchive, float height, float width, float x, float y);
MessageWrapper* createShapeStyleArchiveWrapper(google::protobuf::uint64 styleIdentifier, NSVGshape* shape);

#endif //KEYNOTE_SHAPE_CREATION_REPOSITORY_H
