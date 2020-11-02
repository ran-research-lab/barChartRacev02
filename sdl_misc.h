//
// Created by Rafael Arce Nazario on 11/2/20.
//

#ifndef BARS_SDL_MISC_H
#define BARS_SDL_MISC_H
#include "Dim.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>
#include "LTexture.h"
#include "SDL_ColorDef.h"
bool init(const Dim &D, SDL_Renderer* &renderer, SDL_Window* &window);
bool loadMedia(Font &F);
void close(SDL_Renderer* renderer, SDL_Window* window, Font &F);
void drawText(SDL_Renderer* renderer, int x, int y,
              const SDL_Color& color, std::string txt, TTF_Font *font , int justify);

#endif //BARS_SDL_MISC_H
