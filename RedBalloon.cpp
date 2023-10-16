#include "RedBalloon.h"

//sets color to red and health to 100
RedBalloon::RedBalloon() : Balloon("red", 100) {
}

RedBalloon::~RedBalloon() {} 

void RedBalloon::move(int velocityX, int velocityY) {
    x += velocityX;
    y += velocityY;
}