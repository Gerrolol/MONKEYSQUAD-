#include "cannon.h"

Cannon::Cannon(int x, int y) : Monkey(10 ,100, 40) {
    this->type = 'C';
    this->x = x;
    this->y = y;
    this->cooldown = 0;
}
Cannon::~Cannon() {}

