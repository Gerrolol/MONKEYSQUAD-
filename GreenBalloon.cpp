  #include "GreenBalloon.h"
  
  //sets color to green and health to 300
  GreenBalloon::GreenBalloon() : Balloon("green", 300){
  }

  GreenBalloon::~GreenBalloon(){
  }

  void GreenBalloon::move(int velocityX, int velocityY){
    this->x += 2*velocityX;
    this->y += 2*velocityY;
}
