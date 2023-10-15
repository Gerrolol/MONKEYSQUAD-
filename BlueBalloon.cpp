#include "BlueBalloon.h"
#include "RedBalloon.h"

BlueBalloon::BlueBalloon() : Balloon("blue", 20, 200){
}

BlueBalloon::~BlueBalloon() {}
    
void BlueBalloon::move(int velocityX, int velocityY){
    this->x += 2*velocityX;
    this->y += 2*velocityY;
}

