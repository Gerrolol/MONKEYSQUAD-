#include "cell.h"

Cell::Cell(){
    type = 'E';
}

Cell::~Cell(){}

char Cell::getType(){
    return type;
}

int Cell::checkInRange(std::vector<Balloon*> balloons){
    int closestDistance = sqrt(pow(balloons[0]->getX() - this->x,2)+pow(balloons[0]->getY() - this->y, 2));
    int index = 0;
    int distance = 0;
    for (int i = 1; i< balloons.size();i++){
        distance = sqrt(pow(balloons[i]->getX() - this->x,2)+pow(balloons[i]->getY() - this->y, 2));
        if (distance < closestDistance){
            closestDistance = distance;
            index = i;
        }
        if (distance > range){
            return -1;
        }
    }
    return index;
 }