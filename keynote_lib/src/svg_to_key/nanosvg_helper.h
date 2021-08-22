//
// Created by Jonathan Lampérth on 25.07.21.
//

#ifndef KEYNOTE_NANOSVG_HELPER_H
#define KEYNOTE_NANOSVG_HELPER_H
void  handleNanoSVGFill(TSD::FillArchive* fillArchive, NSVGshape* shape);
void handleNanoSVGStroke(TSD::StrokeArchive *strokeArchive, NSVGshape *shape);
void setLineCap(TSD::StrokeArchive *strokeArchive, char capIdentifier);
void setLineJoin(TSD::StrokeArchive *strokeArchive, char joinIdentifier, float miterLimit);
void setStrokePattern(TSD::StrokeArchive *strokeArchive, NSVGshape *shape);
std::tuple<float, float, float, float> getWidthHeightXY(float bounds[4]);
#endif //KEYNOTE_NANOSVG_HELPER_H
