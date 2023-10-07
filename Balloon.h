#ifndef BALLOON_H
#define BALLOON_H

class Balloon{
protected:
float x;  
float y;  
float velocity_x;  // Velocity in the X direction
float velocity_y;  // Velocity in the Y direction

int health;
float speed;
int reward;

public:
    Balloon(float initialX, float initialY, int initialHealth, int initialReward);
    float GetX() const;
    float GetY() const;
    int GetHealth() const;

    float GetVelocityX() const;
    float GetVelocityY() const;
  
    // Setters for float x, y, velocity_x, velocity_y
    void SetX(float newX);
    void SetY(float newY);
    void SetHealth(int newHealth);

    virtual void SetVelocityX(float newVelocityX);
    virtual void SetVelocityY(float newVelocityY);
    //float update_position_x(float added_x);
    //float update_position_y(float added_y);

    virtual void TakeDamage(int damage);
    bool IsPopped();
};
#endif

  //include in main:
  //for (Balloon& balloon : balloons) {
  //balloon.update_position_x(balloon.GetX() + balloon.GetVelocityX());
  //balloon.update_position_y(balloon.GetY() + balloon.GetVelocityY());

