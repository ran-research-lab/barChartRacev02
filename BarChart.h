//
// Created by Rafael Arce Nazario on 11/1/20.
//

#ifndef BARS_BARCHART_H
#define BARS_BARCHART_H
#include <iostream>
#include <string>
#include <vector>
#include "Bar.h"
#include "Dim.h"

void drawText(SDL_Renderer* renderer, int x, int y,
              const SDL_Color& color, std::string txt, TTF_Font *font , int justify);

class BarChart {
private:
    std::vector<Bar> V;
    std::string title;
    std::string xAxisLabel;
    std::string dataSource;
    std::string caption;
    Dim *D;
    Font *F;
public:
    // Creates a bar chart with the given title, x-axis label, and data source.
    BarChart(const std::string &t, const std::string &xAL, const std::string &dS, Dim *d, Font *f):
        title(t), xAxisLabel(xAL), dataSource(dS), D(d), F(f) {}

    // Sets the caption of this bar chart.
    void setCaption(std::string &c) { caption = c;}

    // Adds a bar (name, value, category) to this bar chart.
    void add(std::string n, int v, std::string cat) {
        V.push_back(Bar(n,v,cat,D,F));
    }

    // Remove all of the bars from this bar chart.
    void reset() { V.clear(); }

    const std::vector<Bar> &getVector() const { return V; }

    void draw(SDL_Renderer* renderer) {
        // determine maxX
        int maxX = V[0].getValue();
        for (auto e: V) {
            if (e.getValue() > maxX) maxX = e.getValue();
        }

        // determine height
        int bcHeight = D->winHeight - D->bcMarginTop - D->bcMarginBottom;
        int ySeparation = bcHeight / (V.size());
        int height = ySeparation * 0.8;
        int y = D->bcMarginTop;
        for (auto e: V) {
            e.draw(renderer,y,height,maxX,RGB_turquoise);
            y += ySeparation;
        }
        drawXAxis(renderer, maxX, 10);
        drawText(renderer,0, D->titleMarginTop,
                 SDL_Color {.r= 0, .g = 0x0, .b = 0, .a = 0xff } ,
                 title, F->fontBig, 0);
        drawText(renderer,D->bcMarginLeft, D->bcMarginTop * 0.7  ,
                 SDL_Color {.r= 0, .g = 0x0, .b = 0, .a = 0xff } ,
                 xAxisLabel, F->fontTiny, 0);
        drawText(renderer,D->winWidth * .67, D->bcMarginTop + bcHeight * 0.75  ,
                 SDL_Color {.r= 0, .g = 0x0, .b = 0, .a = 0xff } ,
                 dataSource, F->fontTiny, 0);
    }


    void drawXAxis(SDL_Renderer* renderer,  int maxX, int numTicks) {
        SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
        float i = 0;
        int bcWidth  = D->winWidth - D->bcMarginLeft - D->bcMarginRight;
        int bcHeight = D->winHeight - D->bcMarginTop - D->bcMarginBottom;

        float tickSeparation = bcWidth / static_cast<float>(numTicks);
        int unitsPerTick = static_cast<float>(maxX) / numTicks;
        int label = 0;
        int tickHeight = .05 * bcHeight;
        while (i <= bcWidth) {
            SDL_RenderDrawLine(renderer, D->bcMarginLeft + i, D->bcMarginTop ,
                               D->bcMarginLeft + i, D->bcMarginTop  + bcHeight );


            drawText(renderer,D->bcMarginLeft + i, D->bcMarginTop - tickHeight,
                     RGB_black ,
                     std::to_string(label), F->fontTiny, 1);
            i += tickSeparation;

            label = label + unitsPerTick;
        }
    }
};


#endif //BARS_BARCHART_H
