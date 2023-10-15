#ifndef BALLOON_H
#define BALLOON_H

#include <string>
#include <SDL2/SDL.h>
#include <map>

class Balloon {
    public:
    Balloon(const std::string& color, int health);
    virtual ~Balloon();

    std::string getColor() const;
    
    bool isPopped();

    void takeDamage(int damage);

    virtual void move(int velocityX, int velocityY);

    //for rendering 
    void setColor(SDL_Color color);

    static std::map<std::string, SDL_Color> colorMap;

    void render(SDL_Renderer* renderer);

    //coordinates of balloon
    float x, y;  

    protected:
    bool popped;
    std::string color;
    int hp;
    SDL_Color colorSDL;
    int radius;
};
#endif 

