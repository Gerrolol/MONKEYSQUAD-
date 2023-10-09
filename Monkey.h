#define MONKEY.H
#include <string>
#ifndef MONKEY.H

class Monkey {
    private:
        int damage;
        int range;
        int cost;
        int attackSpeed;

    
    public:
     Monkey(std::string name, int initialCost, int initialRange, int initialDamage);

};
#endif