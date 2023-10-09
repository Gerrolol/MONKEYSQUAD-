#ifndef BALLOON_H
#define BALLOON_H

#include <string>

class Balloon {
public:
    Balloon(const std::string& color, int value, int health);
    virtual ~Balloon();

    std::string getColor() const;
    
    bool isPopped() const;

    void takeDamage(int damage);

    virtual void pop();

    // Methods for balloon movement
    void move(int velocityX, int velocityY);
    int getX() const;
    int getY() const;
    int getValue();


private:
    mutable bool popped;
    std::string color;
    int x, y;  
    int reward;
    int hp;

};
#endif 

