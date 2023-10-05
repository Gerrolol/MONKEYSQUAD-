#ifndef DART_H
#define DART_H
#include <string>
#include <iostream>


class Dart {
public:
    Dart(std::string name, int initialCost, int initialRange, int initialDamage);
    void attack();

private:
    int cost;
    int damage;
    int range;

};
#endif
