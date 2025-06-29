//
// Created by Jonathan Lampérth on 22.06.21.
//

#include <TSDArchives.pb.h>

#include <memory>
#include "svg_to_key.h"
#include <nanosvg.h>
#include "../../proto_helper.h"
#include "common_message_creation.h"
#include "shape_creation_repository.h"
#include "nanosvg_helper.h"


void addEditablePathFromSVGToPasteboard(std::vector<MessageWrapper *> *messageList, struct NSVGimage *image, google::protobuf::uint64 &currentIdentifier) {
    for (auto* shape = image->shapes; shape != NULL; shape = shape->next) {

        auto* editableBezierPathSourceArchive = new TSD::EditableBezierPathSourceArchive;
        auto [width, height, x, y] = getWidthHeightXY(shape->bounds);
        auto* naturalSize = createSize(width, height);

        editableBezierPathSourceArchive->set_allocated_naturalsize(naturalSize);
        auto* sub_path = editableBezierPathSourceArchive->add_subpaths();
        sub_path->set_closed(true);
        std::vector<float> points = std::vector<float>();


        for (auto* path = shape->paths; path != NULL; path = path->next) {
            auto *bezierPathSourceArchive = new TSD::BezierPathSourceArchive();

            auto* size = createSize(width, height);
            bezierPathSourceArchive->set_allocated_naturalsize(size);

            auto* bez_path = new TSP::Path;

            addPathElement(bez_path, path->pts[0], path->pts[1], TSP::Path_ElementType_moveTo);
            // std::cout << "Path Instance: ";
            for (int i = 0; i < path->npts-1; i += 3) {
                float* p = &path->pts[i*2];
                addBezierPathElement(bez_path, p[2], p[3],p[4], p[5],p[6], p[7]);
            }
            bezierPathSourceArchive->set_allocated_path(bez_path);


            google::protobuf::uint64 shapeInfoIdentifier = currentIdentifier++;
            google::protobuf::uint64 shapeStyleIdentifier = currentIdentifier++;
            auto* shapeInfoArchive = createCustomBezierShapeInfoArchive(shapeInfoIdentifier, shapeStyleIdentifier, bezierPathSourceArchive, height, width, x, y);

            auto* shapeStyleArchive = createShapeStyleArchiveWrapper(shapeStyleIdentifier, shape);

            addStyleReferenceToStylesheet(shapeStyleIdentifier, messageList);
            addDrawableReferenceToPasteboard(messageList, shapeInfoIdentifier, x, y, width, height);

            messageList->push_back(shapeInfoArchive);
            messageList->push_back(shapeStyleArchive);
        }
    }
    // Delete
    nsvgDelete(image);
}

void addStyleReferenceToStylesheet(google::protobuf::uint64 identifier, std::vector<MessageWrapper *> *pVector) {
    for (auto* message : *pVector) {
        if (message->message->GetTypeName() == "TSS.StylesheetArchive") {
            auto* stylesheetArchive = dynamic_cast<TSS::StylesheetArchive*>(message->message);
            stylesheetArchive->add_styles()->set_identifier(identifier);
        }
    }
}

std::tuple<unsigned int, unsigned int, unsigned int, unsigned int> convertColorToRGB(unsigned int color) {
    unsigned int red  = color & 0xff;
    unsigned int green = (color >> 8) & 0xff;
    unsigned int blue = (color >> 16) & 0xff;
    unsigned int opacity = (color >> 24) & 0xff;
    return {red, green, blue, opacity};
}


std::vector<MessageWrapper *> convertSVGFileToKeynoteClipboard(std::string fileContents) { // Return by value
    google::protobuf::uint64 currentIdentifier = 2643663;
    std::vector<MessageWrapper*> messageList; // Local variable
    struct NSVGimage* image;

    image = nsvgParse((char *) fileContents.c_str(), "px", 1);
    // Initialize Identifiers
    google::protobuf::uint64 stylesheetIdentifier = currentIdentifier++;
    google::protobuf::uint64 pasteboardNativeStorageArchiveIdentifier = currentIdentifier++;
    google::protobuf::uint64 pasteboardObjectIdentifier = currentIdentifier++;

    // Create empty initial clipboard
    messageList = createInitialClipboardMessages(pasteboardNativeStorageArchiveIdentifier, pasteboardObjectIdentifier, stylesheetIdentifier); // createInitialClipboardMessages will now return by value

    auto * styleSheetArchiveWrapper = createMessageWrapper(new TSS::StylesheetArchive, 401, stylesheetIdentifier);
    messageList.push_back(styleSheetArchiveWrapper); // Use . for local vector

    // Add shapes to the clipboard
    addEditablePathFromSVGToPasteboard(&messageList, image, currentIdentifier); // Pass address for functions expecting pointer

    // move PasteboardNativeStorage to End
    messageList.push_back(messageList[1]); // Use . for local vector
    messageList.erase(messageList.begin() + 1); // Use . for local vector

    return messageList; // Return local vector by value
}

void addDrawableReferenceToPasteboard(std::vector<MessageWrapper *>* vector, google::protobuf::uint64 identifier, float x, float y, float width, float height) {
    for (auto* message : *vector) {
        if (message->message->GetTypeName() == "TSP.PasteboardObject") {
            TSP::PasteboardObject pbObj = dynamic_cast<TSP::PasteboardObject&>(*message->message);
            auto* newDrawable = pbObj.add_drawables();
            newDrawable->set_identifier(identifier);
            message->message->CopyFrom(pbObj);

            message->archiveInfo->mutable_message_infos(0)->set_length(message->message->SerializeAsString().length());
        }

        if (message->message->GetTypeName() == "KN.PasteboardNativeStorageArchive") {
            KN::PasteboardNativeStorageArchive pbObj = dynamic_cast<KN::PasteboardNativeStorageArchive&>(*message->message);
            auto* newDrawable = pbObj.add_drawables();
            newDrawable->set_identifier(identifier);

            auto* tspSize = createSize(width, height);
            auto* tspPosition = createPoint(x, y);

            auto* tsdGeometryArchive = pbObj.add_geometries_in_root();
            tsdGeometryArchive->set_allocated_size(tspSize);
            tsdGeometryArchive->set_allocated_position(tspPosition);
            tsdGeometryArchive->set_flags(3);
            tsdGeometryArchive->set_angle(0);

            message->message->CopyFrom(pbObj);

            message->archiveInfo->mutable_message_infos(0)->set_length(message->message->SerializeAsString().length());
        }
    }
}

MessageWrapper* createShapeInfoArchive(TSD::EditableBezierPathSourceArchive *editableBezierPathSourceArchive, float width, float height, float x, float y, google::protobuf::uint64 styleIdentifier, google::protobuf::uint64 identifier) {
    auto*  tswpShapeInfoArchive = new TSWP::ShapeInfoArchive;

    // requires only super
    auto*  tsdShapeArchive = new TSD::ShapeArchive;

    // optional .TSD.GeometryArchive geometry = 1;
    auto* tsdDrawableArchive = new TSD::DrawableArchive;

    auto * tsdGeometryArchive = createGeometryArchive(width, height, x, y);

    auto * tsdShapeStyle = new TSP::Reference;
    tsdShapeStyle->set_identifier(styleIdentifier);
    // requires nothing we will add optional TSD::BezierPathSourceArchive
    auto* tsdPathSourceArchive = new TSD::PathSourceArchive;


    tsdPathSourceArchive->set_allocated_editable_bezier_path_source(editableBezierPathSourceArchive);
    tsdPathSourceArchive->set_horizontalflip(false);
    tsdPathSourceArchive->set_verticalflip(false);

    tsdShapeArchive->set_allocated_super(tsdDrawableArchive);
    tsdShapeArchive->set_allocated_pathsource(tsdPathSourceArchive);
    tsdShapeArchive->set_allocated_style(tsdShapeStyle);

    tsdDrawableArchive->set_allocated_geometry(tsdGeometryArchive);

    tswpShapeInfoArchive->set_allocated_super(tsdShapeArchive);

    return createMessageWrapper(tswpShapeInfoArchive, 2011, identifier);
}




std::vector<MessageWrapper *> createInitialClipboardMessages(google::protobuf::uint64 pasteboardNativeStorageArchiveIdentifier, google::protobuf::uint64 pasteboardObjectIdentifier, google::protobuf::uint64 stylesheetIdentifier) { // Return by value
    std::vector<MessageWrapper *> returnVector; // Local variable
    MessageWrapper* pasteboardObjectMessageWrapper = createPasteboardObjectMessageWrapper(pasteboardObjectIdentifier, pasteboardNativeStorageArchiveIdentifier, stylesheetIdentifier);
    MessageWrapper* pasteboardNativeStorageArchiveMessageWrapper = createPasteboardNativeStorageArchiveMessageWrapper(pasteboardNativeStorageArchiveIdentifier);
    returnVector.push_back(pasteboardObjectMessageWrapper); // Use . for local vector
    returnVector.push_back(pasteboardNativeStorageArchiveMessageWrapper); // Use . for local vector

    return returnVector; // Return local vector by value
}


MessageWrapper *createPasteboardNativeStorageArchiveMessageWrapper(google::protobuf::uint64 identifier) {
    auto* pasteboardNativeStorageArchive = new KN::PasteboardNativeStorageArchive();

    pasteboardNativeStorageArchive->set_allocated_originalshowsize(createSize(1920, 1080));
    pasteboardNativeStorageArchive->set_allocated_slide_node_unique_identifier(new std::string("F42146CE-C4D5-494D-B80F-F65103A99A50"));
    pasteboardNativeStorageArchive->set_slide_nodes_have_datas_needing_download(false);

    return createMessageWrapper(pasteboardNativeStorageArchive, 11, identifier);
}

MessageWrapper* createPasteboardObjectMessageWrapper(google::protobuf::uint64 identifier, google::protobuf::uint64 appNativeObjectIdentifier, google::protobuf::uint64 stylesheetIdentifier) {
    auto* appNativeObjectReference = new TSP::Reference();
    appNativeObjectReference->set_identifier(appNativeObjectIdentifier);

    auto* pasteboardObject = new TSP::PasteboardObject();
    pasteboardObject->set_allocated_app_native_object(appNativeObjectReference);


    auto* stylesheet = new TSP::Reference();
    stylesheet->set_identifier(stylesheetIdentifier);
    pasteboardObject->set_allocated_stylesheet(stylesheet);

    return createMessageWrapper(pasteboardObject, 11000, 51);
}



