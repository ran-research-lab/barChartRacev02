//
// Created by Rafael Arce Nazario on 11/2/20.
//
#include "sdl_misc.h"
bool init(const Dim &D, SDL_Renderer* &renderer, SDL_Window* &window) {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        window = SDL_CreateWindow( "SDL Tutorial",
                                   SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                   D.winWidth, D.winHeight,SDL_WINDOW_SHOWN );
        if( window == NULL ) {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else{
            //Create vsynced renderer for window
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( renderer == NULL ) {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else {
                //Initialize renderer color
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }

                //Initialize SDL_ttf
                if( TTF_Init() == -1 ) {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
            }
        }
    }
    return success;
}

bool loadMedia(Font &F) {
    //Loading success flag
    bool success = true;

    //Open the font
    F.font = TTF_OpenFont( "../16_true_type_fonts/DejaVuSans.ttf", 20 );
    if( F.font == NULL ) {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }


    F.fontBig = TTF_OpenFont( "../16_true_type_fonts/DejaVuSans.ttf", 40 );
    if( F.fontBig == NULL ) {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }

    F.fontTiny = TTF_OpenFont( "../16_true_type_fonts/DejaVuSans.ttf", 10 );
    if( F.fontTiny == NULL ) {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    return success;
}

void close(SDL_Renderer* renderer, SDL_Window* window, Font &F) {

    //Free global font
    TTF_CloseFont( F.font );
    TTF_CloseFont( F.fontBig );
    TTF_CloseFont( F.fontTiny );
    F.font = NULL;
    F.fontBig = NULL;
    F.fontTiny = NULL;

    //Destroy window
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window = NULL;
    renderer = NULL;

    //Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void drawText(SDL_Renderer* renderer, int x, int y,
              const SDL_Color& color, std::string txt, TTF_Font *font , int justify = 0){
    LTexture gText(renderer);
    gText.loadFromRenderedText( txt, RGB_black, font );
    if (justify == 1) x = x - gText.getWidth()/2;
    else if (justify == 2) x = - gText.getWidth();
    gText.render( x, y );
}