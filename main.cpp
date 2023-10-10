#include <iostream>
#include <SDL2/SDL.h>
#include <chrono>
#include "Game.h"

Game *game = nullptr;

int main(int argc, char* argv[]) {
    game = new Game();

    game->init("Balloons Tower Defense", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    // Your game code here

    while (game-> running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();


    return EXIT_SUCCESS;
}