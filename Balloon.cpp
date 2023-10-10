#include "Balloon.h"
#include <iostream>
#include <map>
#include <SDL2/SDL.h>

std::map<std::string, SDL_Color> Balloon::colorMap = {
    {"blue", {0, 0, 255, 255}},
    {"red", {255, 0, 0, 255}},
    {"green", {0, 255, 0, 255}}
};

Balloon::Balloon(const std::string& color, int value, int health) 
: color(color), x(50), y(50), popped(false), reward(value), hp(health), radius(10){
 auto colorIt = colorMap.find(color);
    if (colorIt != colorMap.end()) {
        colorSDL = colorIt->second;
    } else {
        colorSDL = {255, 255, 255, 255}; // White
    }
} 

Balloon::~Balloon() {
        if (isPopped()==true){
        delete this;
    }
}

std::string Balloon::getColor() const {
    return color;
}

void Balloon::takeDamage(int damage){
    hp = hp - damage;
}

bool Balloon::isPopped() const {
    if (hp <= 0){
        popped = true;
    }
    return popped;
}

/*void Balloon::pop() {
    if (isPopped()==true){
        delete this;
    }
}*/

void Balloon::move(int velocityX, int velocityY) {
    x += velocityX;
    y += velocityY;
}

int Balloon::getX() const {
    return x;
}

int Balloon::getY() const {
    return y;
}

int Balloon::getValue(){
    return reward;
}

SDL_Color bgColor = {0, 0, 0, 255}; // Black background

void Balloon::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);

    // Clear the screen with the background color
    //SDL_RenderClear(renderer);

    // Set the rendering color to the balloon's color
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