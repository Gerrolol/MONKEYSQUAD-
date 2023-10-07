#include "Balloon.h"
#ifndef REDBALLOON_H
#define REDBALLOON_H

class RedBalloon : public Balloon{

protected:
int RedValue;
float Red_VelocityX;
float Red_VelocityY;

public:
RedBalloon(float initialX, float initialY, int initialHealth, int initialreward);

void SetVelocityX(float newVelocityX) override;
void SetVelocityY(float newVelocityY) override;


};
#endif 

