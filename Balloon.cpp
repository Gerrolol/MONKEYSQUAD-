#include "Balloon.h"
#include <iostream>

Balloon::Balloon(const std::string& color, int value, int health) : color(color), x(0), y(0), popped(false), reward(value), hp(health) {} // Default starting position at (0, 0)

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

void Balloon::pop() {
    if (isPopped()==true){
        delete this;
    }
}

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
