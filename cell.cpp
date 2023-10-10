#include "cell.h"

Cell::Cell(){
    type = 'E';
}

Cell::~Cell(){}

char Cell::getType(){
    return type;
}