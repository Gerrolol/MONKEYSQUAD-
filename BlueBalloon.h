#ifndef BLUEBALLOON_H
#define BLUEBALLOON_H
#include "Balloon.h"

class BlueBalloon : public Balloon{

public:
  BlueBalloon();
  virtual ~BlueBalloon(); 
  //void pop() override;
  void move(int velocityX, int velocityY) override;
  

};
#endif 