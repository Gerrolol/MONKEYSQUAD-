#include "RedBalloon.h"

RedBalloon::RedBalloon(float initialX, float initialY, int initialHealth, int initialreward)
    : Balloon(initialX, initialY, initialHealth, initialreward) {
        this->RedValue = initialreward;
}

void RedBalloon::SetVelocityX(float newVelocityX){ 
    this->Red_VelocityX = newVelocityX;
}

void RedBalloon::SetVelocityY(float newVelocityY){
    this->Red_VelocityY = newVelocityY;
}
