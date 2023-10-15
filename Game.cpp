#include "Game.h"
#include "Balloon.h" 
#include "RedBalloon.h"
#include "BlueBalloon.h" 
#include "GreenBalloon.h"
#include <vector>

std::vector<Balloon*> balloons; 

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
    
        RedBalloon* redBalloon = new RedBalloon();
        BlueBalloon* blueBalloon = new BlueBalloon();
        GreenBalloon* greenBalloon = new GreenBalloon();

        balloons.push_back(new RedBalloon());
        balloons.push_back(new BlueBalloon());
        balloons.push_back(new GreenBalloon());
    
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
                int mouseX = 0, mouseY = 0;
                SDL_GetMouseState(&mouseX, &mouseY);
                int mousePos = mouseX/48 + (mouseY/48)*16;
                if (Level.listCells[mousePos]->getType() == 'L'){
                    std::cout << "Which Monkey?" << std::endl;
                    std::cout << "S for Sniper, D for darts, C for Cannon." << std::endl;
                    std::cin >> MonkeyTypeChosen;
                    while (MonkeyTypeChosen!='D'&&MonkeyTypeChosen!='S'&&MonkeyTypeChosen!='C'){
                        std::cout << "Invalid choice, try again: " << std::endl;
                        std::cin >> MonkeyTypeChosen;
                    }
                    switch (MonkeyTypeChosen) {
                    case 'D':
                        std::cout << "Dart Placed." << std::endl;
                        Level.setCell(mousePos,'D');
                        break;
                    case 'C':
                        std::cout << "Cannon Placed." << std::endl;
                        Level.setCell(mousePos,'C');
                        break;
                    case 'S':
                        std::cout << "Sniper." << std::endl;
                        Level.setCell(mousePos,'S');
                        break;
                    default:
                        break;
                    }
                }else{
                    std::cout<< "You can only place on grass!"<< std::endl;
                }
            }
            
        case SDL_MOUSEBUTTONUP:
            mouseDownStatus = 0;

        default:
            break;
    }
}

void Game::update(){
int balloonToPop = -1;
for (int i = 0; i< Level.listCells.size();i++){
    if (Level.listCells[i]->getType() == 'D' ||Level.listCells[i]->getType() == 'S' ||Level.listCells[i]->getType() == 'C'){
        balloonToPop = Level.listCells[i]->checkInRange(balloons);
        if (Level.listCells[i]->cooldown > 0){
            Level.listCells[i]->cooldown -=1;
        }else if (balloonToPop >-1){
            switch (Level.listCells[i]->getType()){
                case 'D':
                    std::cout<<"shot a dart"<<std::endl;
                    balloons[balloonToPop]->takeDamage(100);
                    Level.listCells[i]->cooldown = 90;
                    break;
                case 'S':
                    balloons[balloonToPop]->takeDamage(300);
                    Level.listCells[i]->cooldown = 180;
                    break;
                case 'C':
                    float distance = 0;
                    for (int i = 1; i< balloons.size();i++){
                    distance = sqrt(pow(balloons[i]->x - Level.listCells[i]->x,2)+pow(balloons[i]->y - Level.listCells[i]->y, 2));
                    if (distance < 24){
                        balloons[i]->takeDamage(100);
                    }
                    Level.listCells[i]->cooldown = 120;
            }
            }
        }
    }
}
if (balloons.empty() == true && currentWave == 3){
    isRunning = false;
}else{
    for (size_t i = 0; i < balloons.size(); ++i) {
            Balloon* balloon = balloons[i];
        
            if (balloon->y < 220 || (balloon->x <= 650 && balloon->y >= 700)) {
                balloon->move(0, 1); // Move down
            }
            else if (balloon->x < 600 && balloon->y >= 220 && balloon->y < 400) {
                balloon->move(1, 0); // Move right
            }
            else if (balloon->y < 400) {
                balloon->move(0, 1); // Move down
            }
            else if (balloon->y >= 370 && balloon->x > 160) {
                balloon->move(-1, 0); // Move left
            }
            else {
                balloon->move(0, 1); // Move down
                if (balloon->y <= 610){
                    isRunning = false;
                    break;
                }
            }

            if (balloon->isPopped()) {
                int poppedX = balloon->x;
                int poppedY = balloon->y;
                if (balloon->getColor() == "blue") {

                    balloons.erase(balloons.begin() + i);
                    delete balloon;
                    RedBalloon* newBalloon = new RedBalloon();
                    newBalloon->move(poppedX-170, poppedY-10);
                    balloons.push_back(newBalloon);
                }
                
                else if (balloon->getColor() == "green") {
                    balloons.erase(balloons.begin() + i);
                    delete balloon;

                    BlueBalloon* newBalloon = new BlueBalloon();
                    newBalloon->move((poppedX-170)/1.5, (poppedY-10)/1.5);

                    balloons.push_back(newBalloon);
                }

                else if (balloon->getColor() == "red") {
                    balloons.erase(balloons.begin() + i);
                    delete balloon;
                }
        }
}
}
}

void Game::render(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    Level.draw(renderer, cellSize);
    //balloons[0]->render(renderer);
        for (size_t i = 0; i < balloons.size(); ++i) {
        balloons[i]->render(renderer);
        }
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