#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <vector>
#include <cmath>
#include "Balloon.h"

class Cell {
    private:

    public:
    char type;
    char getType();
    Cell();
    ~Cell();
    int cooldown;
    int range;
    int x,y;
    int checkInRange(std::vector<Balloon*> balloons);
};

#endif