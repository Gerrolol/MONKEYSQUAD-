#include "Balloon.h"
#ifndef REDBALLOON_H
#define REDBALLOON_H

class RedBalloon : public Balloon{
  
public:
  RedBalloon();
  virtual ~RedBalloon(); 
  void move(int velocityX, int velocityY) override;

};
#endif 

