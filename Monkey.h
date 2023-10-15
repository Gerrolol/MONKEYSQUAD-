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

        void shoot(Balloon& target);

        int getRange();

        void setColor(SDL_Color color);

        static std::map<std::string, SDL_Color> colorMap;

        void render(SDL_Renderer* renderer);

    protected:
        int damage;
        int range;
        int atkspeed;
        int x2, y2;

};
#endif