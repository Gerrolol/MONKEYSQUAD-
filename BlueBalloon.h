#ifndef BLUEBALLOON_H
#define BLUEBALLOON_H
#include "Balloon.cpp"

class BlueBalloon : public Balloon{

public:
  BlueBalloon();
  virtual ~BlueBalloon(); 
  void pop() override;
  

};
#endif 