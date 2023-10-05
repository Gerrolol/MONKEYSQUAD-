#include <iostream>
#include <SDL2/SDL.h>


int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "error";
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("My SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // Your game code here
    SDL_Event windowEvent;

    while (true)
    {
        if( SDL_PollEvent(&windowEvent))
        {
            if( SDL_QUIT == windowEvent.type)
            {break;}
        }
    }


    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}