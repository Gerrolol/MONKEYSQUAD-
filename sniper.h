#ifndef SNIPER_H
#define SNIPER_H
#include <string>
#include <iostream>

class Sniper {
public:
     Sniper(std::string name, int initialCost, int initialRange, int initialDamage);

     void attack();
private:
    int cost;
    int damage;
    int range;



};
#endif