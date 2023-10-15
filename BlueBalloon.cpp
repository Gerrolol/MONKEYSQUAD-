#include "BlueBalloon.h"
#include "RedBalloon.h"

BlueBalloon::BlueBalloon() : Balloon("blue", 20, 200){
}

BlueBalloon::~BlueBalloon() {}
    
void BlueBalloon::move(int velocityX, int velocityY){
    this->x += (float)1.5*velocityX;
    this->y += (float)1.5*velocityY;
}

