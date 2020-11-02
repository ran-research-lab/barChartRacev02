//
// Created by Rafael Arce Nazario on 11/1/20.
//

#ifndef BARS_DIM_H
#define BARS_DIM_H
#include <SDL_ttf.h>

struct Dim {
    int winHeight, winWidth;
    int bcMarginLeft, bcMarginRight;
    int bcMarginTop, bcMarginBottom;
    int titleMarginTop;
};

struct Font {
    TTF_Font *fontTiny = NULL;
    TTF_Font *font = NULL;
    TTF_Font *fontBig = NULL;
};
#endif //BARS_DIM_H
