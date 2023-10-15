  #include "GreenBalloon.h"
  
  GreenBalloon::GreenBalloon() : Balloon("green", 40, 300){
  }

  GreenBalloon::~GreenBalloon(){
  }

  void GreenBalloon::move(int velocityX, int velocityY){
    this->x += 2*velocityX;
    this->y += 2*velocityY;
}
