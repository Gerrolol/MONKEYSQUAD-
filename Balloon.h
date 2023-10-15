#ifndef BALLOON_H
#define BALLOON_H

#include <string>
#include <SDL2/SDL.h>
#include <map>

class Balloon {
    public:
    Balloon(const std::string& color, int value, int health);
    virtual ~Balloon();

    std::string getColor() const;
    
    bool isPopped() const;

    void takeDamage(int damage);

    //virtual void pop();

    // Methods for balloon movement
    virtual void move(int velocityX, int velocityY);
    int getX() const;
    int getY() const;
    int getValue();

    //for rendering 
    void setColor(SDL_Color color);

    static std::map<std::string, SDL_Color> colorMap;

    void render(SDL_Renderer* renderer);

    protected:
    mutable bool popped;
    std::string color;
    int x, y;  
    int reward;
    int hp;
    SDL_Color colorSDL;
    int radius;
};
#endif 

