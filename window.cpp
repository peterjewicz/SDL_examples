#include <iostream>

#include <SDL2/SDL.h>

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, const char * argv[]) {
    if (SDL_Init( SDL_INIT_EVERYTHING) < 0) {
        std::cout << "SDL ERROR";
    }

    SDL_Window *window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    SDL_Event windowEvent;

    while (true) {
        if (SDL_PollEvent(&windowEvent)){
            if(SDL_QUIT == windowEvent.type){
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
