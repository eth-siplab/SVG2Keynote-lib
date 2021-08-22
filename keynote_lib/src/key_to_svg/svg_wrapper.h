//
// Created by Jonathan Lampérth on 08.05.21.
//

#ifndef KEYNOTE_SVG_WRAPPER_H
#define KEYNOTE_SVG_WRAPPER_H

// todo: declare this class inside of public header file, so does not need to be imported when using the library
// todo: possible create 2 public header files, one for key->svg and vise versa

#include <sstream>

class svg_wrapper {
private:
    std::stringstream svgStringStream;
    int test;
public:
    svg_wrapper();
    void initializeSVG(float width, float height);
    void endSVG();
    void createPlaceholderRectangle(float x, float y, float width, float height);
    void addString(std::string toAdd);

    std::string getString();
};


#endif //KEYNOTE_SVG_WRAPPER_H
