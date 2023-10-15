#ifndef BLUEBALLOON_H
#define BLUEBALLOON_H
#include "Balloon.h"

class BlueBalloon : public Balloon{

public:
  BlueBalloon();
  virtual ~BlueBalloon(); 
  void move(int velocityX, int velocityY) override; //overrides as velocity of blue balloon is larger
  

};
#endif 