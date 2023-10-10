#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include <iostream>
#include <chrono>
#include "Balloon.h"  
#include "Map.h"

class Game{
    public:
    Game::Game();
    ~Game();
    Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running(){return isRunning;}

    private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    const int cellSize = 48;
    Map Level;
    int mouseDownStatus = 0;

};

#endif