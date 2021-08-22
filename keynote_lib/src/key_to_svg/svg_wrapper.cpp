//
// Created by Jonathan Lampérth on 08.05.21.
//

#include "svg_wrapper.h"



svg_wrapper::svg_wrapper() = default;

void svg_wrapper::initializeSVG (float width, float height) {
    svgStringStream << "<svg "
       << "width=\"" << width << "px\""
       << " height=\"" << height << "px\" "
       << R"(xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" version="1.1">)" << std::endl;
}

void svg_wrapper::endSVG() {
    svg_wrapper::svgStringStream << "</svg>" << std::endl;
}

std::string svg_wrapper::getString() {
    return svg_wrapper::svgStringStream.str();
}

void svg_wrapper::createPlaceholderRectangle(float x, float y, float width, float height) {
   svgStringStream << "<rect x=\"" << x << "\" y=\"" << y << "\" height=\"" << height << "\" width=\"" << width << "\" />" << std::endl;
}

void svg_wrapper::addString(std::string toAdd) {
    svgStringStream << toAdd << std::endl;
}
