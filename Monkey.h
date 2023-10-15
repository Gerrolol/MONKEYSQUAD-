#ifndef MONKEY_H
#define MONKEY_H
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <map>
#include "Balloon.h"
#include "cell.h"

class Monkey :public Cell{
    public:
        Monkey(int atkspeed, int range, int damage);
        
    protected:
        int damage;
        int atkspeed;

};
#endif