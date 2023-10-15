#include "BlueBalloon.h"
#include "RedBalloon.h"

//creates a blue balloon with 200 health
BlueBalloon::BlueBalloon() : Balloon("blue", 200){
}

BlueBalloon::~BlueBalloon() {}
    
void BlueBalloon::move(int velocityX, int velocityY){
    this->x += (float)1.5*velocityX;
    this->y += (float)1.5*velocityY;
}

