//
// Created by Jonathan Lampérth on 09.08.21.
//

#include <vector>
#include "key_to_svg.h"
#include "../../proto_helper.h"
#include "../../snappy_helper.h"
#include "svg_wrapper.h"
#include "../../models/SlideObjects/SlideObject.h"
#include "../../models/SlideObjects/SlideObjectFactory.h"


std::string convertVectorOfIWAFilesToSVG(const std::vector<keynoteIWAFile>& entries) {
    svg_wrapper svg;


    for (const keynoteIWAFile& entry : entries) {
        std::vector<MessageWrapper* > fileProtos = convertProtobufToListOfMesssages(processIWAFile(entry.contents));
        for(MessageWrapper* mw: fileProtos) {
            google::protobuf::Message* p = mw->message;
            if(p->GetTypeName() == "KN.ShowArchive") {
                // get canvas size and initialize
                KN::ShowArchive showArchive = dynamic_cast<KN::ShowArchive &>(*p);
                float width = showArchive.size().width();
                float height = showArchive.size().height();
                svg.initializeSVG(width, height);
            }

            else if (p->GetTypeName() == "TSWP.ShapeStyleArchive") {
                TSWP::ShapeStyleArchive shapeInfo;
                shapeInfo = dynamic_cast<TSWP::ShapeStyleArchive&>(*p);
                // todo: parse shape style
            }
            else if (entry.name.rfind("Index/Slide", 0) == 0) {
                SlideObject *  oj = SlideObjectFactory::GetSlideObject(mw->type, *p);
                svg.addString(oj->getSVG());
            }

            delete p;
        }
    }
    svg.endSVG();
    return svg.getString();
}
