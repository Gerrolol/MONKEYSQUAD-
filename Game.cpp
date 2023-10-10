#include "Game.h"
#include "Game.h"
#include "Balloon.h" 
#include "RedBalloon.h"
#include "BlueBalloon.h" 
#include "GreenBalloon.h"
#include <vector>
#include "path.h"

std::vector<Balloon*> balloons; 


Game::Game(){}

Game::~Game(){}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flags = 0;
    if (fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Initialised subsystems"<< std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window){
            std::cout<< "window created"<< std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);
        if (renderer){
            std::cout<< "renderer created"<< std::endl;
        }
        isRunning = true;
    }else{
        isRunning = false;
    }
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent (&event);
    switch (event.type){
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }
}

void Game::update(){
for (size_t i = 0; i < balloons.size(); ++i) {
        Balloon* balloon = balloons[i];


        //code the movement of the balloon here
        //
        
    
        if (balloon->isPopped()) {
            if (balloon->getColor() == "blue") {

                 int poppedX = balloon->getX();
                 int poppedY = balloon->getY();

                balloons.erase(balloons.begin() + i);
                delete balloon;

                RedBalloon* newBalloon = new RedBalloon();
                newBalloon->move(poppedX, poppedY);
                balloons.push_back(newBalloon);
            }
            else if (balloon->getColor() == "green") {

                int poppedX = balloon->getX();
                int poppedY = balloon->getY();

                balloons.erase(balloons.begin() + i);
                delete balloon;

                BlueBalloon* newBalloon = new BlueBalloon();
                newBalloon->move(poppedX, poppedY);

                balloons.push_back(newBalloon);
            }

            else if (balloon->getColor() == "red") {
                balloons.erase(balloons.begin() + i);
                delete balloon;
            }
        }
}
}

void Game::render(){
    SDL_RenderClear(renderer);
    //add stuff to render
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<< "Cleaned Game"<<std::endl;
}