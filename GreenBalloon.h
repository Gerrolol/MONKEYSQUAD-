#ifndef GREENBALLOON_H
#define GREENBALLOON_H
#include "Balloon.h"

class GreenBalloon : public Balloon{

public:
  GreenBalloon();
  virtual ~GreenBalloon(); 
  void move(int velocityX, int velocityY) override;
  
};
#endif 