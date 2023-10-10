#include "Game.h"
#include "Balloon.h" 
#include "RedBalloon.h"
#include "BlueBalloon.h" 
#include "GreenBalloon.h"
#include <vector>

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
    RedBalloon* redBalloon = new RedBalloon();
    balloons.push_back(redBalloon);
    /*
        RedBalloon* redBalloon = new RedBalloon();
        BlueBalloon* blueBalloon = new BlueBalloon();
        GreenBalloon* greenBalloon = new GreenBalloon();

        balloons.push_back(new RedBalloon());
        balloons.push_back(new BlueBalloon());
        balloons.push_back(new GreenBalloon());
    */
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
        // Update the position of the balloon
        balloon->move(1,0);

}
}

/*for (size_t i = 0; i < balloons.size(); ++i) {
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
*/

void Game::render(){
    SDL_RenderClear(renderer);

    balloons[0]->render(renderer);
    //add stuff to render
        //for (size_t i = 0; i < balloons.size(); ++i) {
        //balloons[i]->render(renderer);
        //}
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    // Clean up balloons and their memory
    for (size_t i = 0; i < balloons.size(); ++i) {
        delete balloons[i];
    }
    balloons.clear();

    //clean up SDL resources
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<< "Cleaned Game"<<std::endl;
}