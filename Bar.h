//
// Created by Rafael Arce Nazario on 11/1/20.
//

#include <iostream>
#include <string>
#ifndef BARS_BAR_H
#define BARS_BAR_H

#include "Dim.h"
class Bar {
private:
    std::string name;
    int value;
    std::string category;
    Dim *D;
    Font *F;
public:
    Bar(std::string n, int v, std::string cat, Dim *d, Font *f)
        :name(n), value(v), category(cat), D(d), F(f) {};
    std::string getName() const {return name;}
    std::string getCategory() const {return category;}
    int getValue() const {return value;}
    bool operator<(const Bar &other) const {
        return (value < other.value);
    }
    std::string toString() const {
        return name + " " +  std::to_string(value) + " " + category;
    }

    void draw(SDL_Renderer* renderer, int y, int height, int maxX, const SDL_Color& color){
        // compute the position
        int x = D->bcMarginLeft;
        int width = (D->winWidth - D->bcMarginLeft - D->bcMarginRight) *  (value * 1.0) / maxX;
//        std::cout << D->winWidth - D->bcMarginLeft - D->bcMarginRight << std::endl;
//        std::cout << width << std::endl;

        SDL_Rect fillRect = { x, y, width, height };
        SDL_SetRenderDrawColor( renderer, color.r, color.g, color.b, color.a );
        SDL_RenderFillRect( renderer, &fillRect );
        LTexture gText(renderer);
        gText.loadFromRenderedText( name.c_str(), { 0, 0, 0 }, F->font );
        gText.render( D->bcMarginLeft +  width - gText.getWidth()  , y +  height/2 - gText.getHeight()/2 );

        LTexture gTextValue(renderer);
        gTextValue.loadFromRenderedText( std::to_string(value), { 0, 0, 0 }, F->fontTiny );
        gTextValue.render( D->bcMarginLeft + width , y + height/2 - gTextValue.getHeight()/2 );
    }

};


#endif //BARS_BAR_H
