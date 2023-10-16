#include "Balloon.h"
#include <iostream>
#include <map>
#include <SDL2/SDL.h>

//creates the blue, red, green color possibilites
std::map<std::string, SDL_Color> Balloon::colorMap = {
    {"blue", {0, 0, 255, 255}},
    {"red", {255, 0, 0, 255}},
    {"green", {0, 255, 0, 255}}
};

//Default balloon constructor 
Balloon::Balloon(const std::string& color, int health) 
: color(color), x(170), y(10), popped(false), hp(health), radius(10){
 auto colorIt = colorMap.find(color); //checks if color is in color map.
    if (colorIt != colorMap.end()) { 
        colorSDL = colorIt->second;
    } 
}

//destructor
Balloon::~Balloon() {}

// returns color of balloon
std::string Balloon::getColor() const {
    return color;
}

//subtract damage from hp of balloon
void Balloon::takeDamage(int damage){
    hp = hp - damage;
}

//return true if balloon is popped otherwise returns false
bool Balloon::isPopped(){
    return hp <= 0;
}

void Balloon::render(SDL_Renderer* renderer) {

    SDL_SetRenderDrawColor(renderer, colorSDL.r, colorSDL.g, colorSDL.b, colorSDL.a);

    // Render the filled circle
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w; // Horizontal offset
            int dy = radius - h; // Vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}