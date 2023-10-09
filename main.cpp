#include <iostream>
#include <SDL2/SDL.h>
#include <chrono>
#include "Game.h"

Game *game = nullptr;

int main(int argc, char* argv[]) {
    game = new Game("Balloons Tower Defense", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    auto time1 = std::chrono::system_clock::now();
    auto time2 = std::chrono::system_clock::now();
    const float dT = 1.0f/60.0f;

    while (game-> running())
    {
        time2 = std::chrono::system_clock::now();
        std::chrono::duration<float> timeElapsed = time2 - time1;
        float timeElapsedFloat = timeElapsed.count();

        if (timeElapsedFloat >= dT){
            time1 = time2;
            game->handleEvents();
            game->update();
            game->render();
        }
    }

    game->clean();

    return EXIT_SUCCESS;
}