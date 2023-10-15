#include "cell.h"

Cell::Cell(){
    type = 'E';
    range = 0;
}

Cell::~Cell(){}

char Cell::getType(){
    return type;
}

int Cell::checkInRange(std::vector<Balloon*> balloons){
    if(balloons.empty()){
        return -1;
    }
    int closestDistance = sqrt(pow(balloons[0]->x - this->x,2)+pow(balloons[0]->y - this->y, 2));
    int index = 0;
    float distance = 0;
    for (int i = 1; i< balloons.size();i++){
        distance = sqrt(pow(balloons[i]->x - this->x,2)+pow(balloons[i]->y - this->y, 2));
        if (distance < closestDistance){
            closestDistance = distance;
            index = i;
        }
        if (closestDistance > this->range){
            return -1;
        }
    }
    return index;
 }