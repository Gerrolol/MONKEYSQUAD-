#include "sniper.h"

//creates an instance of a monkey with 1000 range
Sniper::Sniper(int x , int y) : Monkey(20 ,1000, 20) {
    this->type = 'S';
    this->x = x;
    this->y = y;
    this->cooldown = 0;
}
Sniper::~Sniper() {}