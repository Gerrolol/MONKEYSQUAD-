#include "Monkey.h"
#include <SDL2/SDL.h>
#include "Balloon.h"
#include <cmath>

// Constructor
Monkey::Monkey(int atkspeed, int range, int damage)
    : atkspeed(atkspeed), range(range), damage(damage) {
    // Initialize the monkey's properties
}

// Implement the shoot method
void Monkey::shoot(Balloon& target) {
    // Check if a bloon is in range and shoot it
    int distance = sqrt(pow(target.getX() - x2, 2) + pow(target.getY() - y2, 2));
    if (range >= distance){
        target.takeDamage(damage);
    } 
        // Implement the logic to damage the bloon here
}

// Getter for range
int Monkey::getRange(){
    return range;
}

void Monkey::render(SDL_Renderer* renderer) {
    // Implement rendering logic using SDL2
    // You'll need to render the monkey's image or shape on the map

    // Example: rendering a simple rectangle as a placeholder
 SDL_Rect rect;
rect.x = x2;
rect.y = y2;
rect.w = 20; // Replace with the monkey's width
rect.h = 20; // Replace with the monkey's height

SDL_RenderFillRect(renderer, &rect);
SDL_RenderPresent(renderer);
}
