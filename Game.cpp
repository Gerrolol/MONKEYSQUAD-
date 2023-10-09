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

Game::Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
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
    Level = Map(renderer, width / cellSize, height/ cellSize);
    for (int i=0; i<192;i++){
        Level.setCell(i,'L');
    }
    int PathPos[30] = {3,19,35,51,67,68,69,70,71,72,73,74,75,76,92,108,124,140,139,138,137,136,135,134,133,132,131,147,163,179};
    for (int i=0; i<30; i++){
        Level.setCell(PathPos[i],'P');
    }
    int WaterPos[18] = {13,22,23,24,29,30,39,40,46,47,97,98,99,169,170,171,186,187};
    for (int i=0; i<18; i++){
        Level.setCell(WaterPos[i],'W');
    }
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent (&event);
    switch (event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT){
                mouseDownStatus = SDL_BUTTON_LEFT;
            }
        case SDL_MOUSEBUTTONUP:
            mouseDownStatus = 0;

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
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    Level.draw(renderer, cellSize);
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<< "Cleaned Game"<<std::endl;
}