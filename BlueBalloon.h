#ifndef BLUEBALLOON_H
#define BLUEBALLOON_H
#include "Balloon.cpp"

class BlueBalloon : public Balloon{
    
private:
int BlueValue;
float Blue_VelocityX;
float Blue_VelocityY;
bool HasTurnedRed;

public:
BlueBalloon(float initialX, float initialY, int initialHealth, int initialreward);

void SetVelocityX(float newVelocityX) override;
void SetVelocityY(float newVelocityY) override;
void TakeDamage(int damage) override;




};
#endif 