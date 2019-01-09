//
//  main.cpp
//  SDL_Test
//
//  Created by Peter Jewicz on 1/8/19.
//  Copyright © 2019 Peter Jewicz. All rights reserved.
//



// Product > Scheme > Edit Scheme... > Options, check Use custom working directory
// Lets you place the images in the same directory and loads them correclty

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int WIDTH = 800, HEIGHT = 600;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;
// Reference to events happening in the window
SDL_Event windowEvent;

//Starts up SDL and creates window
bool init() {
    //Initialization flag
    bool success = true;
    gWindow = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    
    gScreenSurface = SDL_GetWindowSurface( gWindow );
    return success;
}

//Loads media
bool loadMedia() {
    //Loading success flag
    bool success = true;
    
    //Load splash image
    gHelloWorld = IMG_Load("youtube.jpg");
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "image.bmp", SDL_GetError() );
        success = false;
    }
    
    return success;
}

//Frees media and shuts down SDL
void close() {
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;
    
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    
    //Quit SDL subsystems
    SDL_Quit();
}

int main(int argc, const char * argv[]) {
    if (SDL_Init( SDL_INIT_EVERYTHING) < 0) {
        std::cout << "SDL ERROR";
    }
    
    init();
    loadMedia();
    SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
    SDL_UpdateWindowSurface( gWindow );


    while(true){
        if (SDL_PollEvent(&windowEvent)){
            if(SDL_QUIT == windowEvent.type){
                break;
            }
        }
    }
    
    close();
    return 0;
}
