#include "Game.h"
#include "Balloon.h" 
#include "RedBalloon.h"
#include "BlueBalloon.h" 
#include "GreenBalloon.h"
#include <vector>

std::vector<Balloon*> balloons; 

Game::~Game(){}

//creates game window and sets initial map.
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
        //exit buton to exit
        case SDL_QUIT:
            isRunning = false;
            break;
        
        //when left click, checks if cell is a land, and if it is will prompt user on what type of monkey they would like to place
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
                        //prompts user to try again to input id input is wrong
                        std::cout << "Invalid choice, try again: " << std::endl;
                        std::cin >> MonkeyTypeChosen;
                    }
                    //sets cell at location of mouse to desired monkey type.
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
                    //warning if the player clicks on a non-grass tile.
                    std::cout<< "You can only place on grass!"<< std::endl;
                }
            }
            
        case SDL_MOUSEBUTTONUP:
            //resets the mouse button status
            mouseDownStatus = 0;
            break;

        default:
            break;
    }
}


void Game::update(){

    balloonSpawnTimer++;
    if (balloonSpawnTimer >= 60 && spawnCount <10) {
        RedBalloon* redBalloon = new RedBalloon();
        balloons.push_back(redBalloon);
        balloonSpawnTimer = 0; 
        spawnCount++;
    }
    if(spawnCount >= 10 && spawnCount < 15 && balloonSpawnTimer >=60){
        BlueBalloon* blueBalloon = new BlueBalloon();
        balloons.push_back(blueBalloon);
        balloonSpawnTimer =0;
        spawnCount++;
    }
        if(spawnCount >= 15 && spawnCount < 20 && balloonSpawnTimer >=60){
        GreenBalloon* greenBalloon = new GreenBalloon();
        balloons.push_back(greenBalloon);
        balloonSpawnTimer =0;
        spawnCount++;
    }
    

int balloonToPop = -1;
//loops through list of cells and finds monkeys
for (int i = 0; i< Level.listCells.size();i++){
    if (Level.listCells[i]->getType() == 'D' ||Level.listCells[i]->getType() == 'S' ||Level.listCells[i]->getType() == 'C'){
        //check if monkey is on cooldown
        balloonToPop = Level.listCells[i]->checkInRange(balloons);
        if (Level.listCells[i]->cooldown > 0){
            Level.listCells[i]->cooldown -=1;
        }else if (balloonToPop >-1){
            //checks type of monkey and shoots accordingly, then resets cooldown
            switch (Level.listCells[i]->getType()){
                case 'D':
                    std::cout<<"shot a dart"<<std::endl;
                    balloons[balloonToPop]->takeDamage(100);
                    Level.listCells[i]->cooldown = 90;
                    break;
                case 'S':
                    std::cout<<"SNIPE"<<std::endl;
                    balloons[balloonToPop]->takeDamage(300);
                    Level.listCells[i]->cooldown = 180;
                    break;
                case 'C':
                    std::cout<<"boom"<<std::endl;
                    float distance = 0;
                    for (int i = 0; i< balloons.size();i++){
                        distance = sqrt(pow(balloons[i]->x - balloons[balloonToPop]->x,2)+pow(balloons[i]->y - balloons[balloonToPop]->y, 2));
                        if (distance < 24){
                            balloons[i]->takeDamage(100);
                        }
                    }
                    Level.listCells[i]->cooldown = 120;
                    break;
            }
        }
    }
}
//win condition - all balloons spawned and dead.
if (balloons.empty() == true && spawnCount == 20){
    isRunning = false;
    std::cout<< "You Won!" << std::endl;
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
                if (balloon->y >= 610){
                    isRunning = false;
                    std::cout<< "Blud got popped!"<< std::endl;
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
    //reders the updates screen
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