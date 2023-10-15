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

 int Monkey::checkInRange(Balloon& array){
    
 }
