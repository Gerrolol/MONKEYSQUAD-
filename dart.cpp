#include "dart.h"

Dart::Dart(int x, int y) : Monkey(20 ,100, 20) {
    this->x = x;
    this->y = y;
    this->type = 'D';
    this->cooldown = 0;
}
Dart::~Dart() {}