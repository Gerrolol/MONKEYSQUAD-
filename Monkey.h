#ifndef MONKEY_H
#include <string>
#define MONKEY_H

class Monkey {
    private:
        int damage;
        int range;
        int cost;
        int attackSpeed;

    
    public:
    Monkey(std::string name, int initialCost, int initialRange, int initialDamage);
    void upgrade(int newRange, int newDamage);
};
#endif