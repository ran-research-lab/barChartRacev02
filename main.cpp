/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, SDL_ttf, standard IO, math, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include "LTexture.h"
#include <string>
#include "Dim.h"
#include "SDL_ColorDef.h"
#include "sdl_misc.h"

//#define CATCH_CONFIG_RUNNER
//#include "catch.hpp"

#include "Bar.h"
#include "BarChart.h"

// drawRect:
//    renderer: pointer to an SDL_Renderer object
//    x, y, width, height: position and dimensions of the rectangle
//    color: an SDL_color structure that contains r,g,b,and a values
//    txt: the text that will be printed (right justified) inside the rectangle





void initDimensions(Dim &D) {
    D.winWidth  = 640;
    D.winHeight = 480;
    D.bcMarginLeft = D.bcMarginRight = D.winWidth * 0.05;
    D.bcMarginTop = D.winHeight * .20;
    D.bcMarginBottom = D.winHeight * .05;
}

int main( int argc, char* argv[] ) {
    Dim D;
    Font F;
    SDL_Renderer* renderer = NULL;
    SDL_Window* window = NULL;
    initDimensions(D);

    BarChart BC("algo", "ahi", "quenose", &D,&F);
    BC.add("Cuba", 345, "Caribbean");
    BC.add("Mexico", 1200, "North America");
    BC.add("PR", 900, "Caribbean");
    BC.add("Canada", 500, "North America");

	//Start up SDL and create window
	if( !init(D,renderer,window) ) { printf( "Failed to initialize!\n" ); }
	else { //Load media
		if( !loadMedia(F) ) { printf( "Failed to load media!\n" ); }
		else { //Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit ) {
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 ) {
					//User requests quit
					if( e.type == SDL_QUIT ) {
						quit = true;
					}

					else if (e.type == SDL_KEYDOWN ) {
						if ( e.key.keysym.sym== SDLK_q)  quit = true;
						if ( e.key.keysym.sym== SDLK_d) {
							//idx = (idx + 1) % data.size();

						}
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( renderer );
                BC.draw(renderer);

                //Update screen
				SDL_RenderPresent( renderer );
			}
		}
	}

	//Free resources and close SDL
	close(renderer, window, F);

	return 0;
}