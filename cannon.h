#ifndef CANNON_H
#define CANNON_H
#include <string>
#include <iostream>

class Cannon {
public:
     Cannon(std::string name, int initialCost, int initialRange, int initialDamage);

     void attack();
private:
    int cost;
    int damage;
    int range;



};
#endif