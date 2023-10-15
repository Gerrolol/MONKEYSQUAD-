#include "Monkey.h"
#include <SDL2/SDL.h>
#include "Balloon.h"
#include <cmath>
#include <vector>


// Constructor
Monkey::Monkey(int atkspeed, int range, int damage)
    : atkspeed(atkspeed), damage(damage) {
        this->range = range;
    // Initialize the monkey's properties
}
