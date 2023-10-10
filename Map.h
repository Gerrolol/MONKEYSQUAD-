#ifndef MAP_H
#define MAP_H
#include <vector>
#include "cell.h"
#include "SDL2/SDL.h"
#include <string>
#include <iostream>

class Map{
    public:
    Map(SDL_Renderer* renderer, int nCellRows, int nCellCols);
    void draw(); //draws whole map
    virtual std::string returnCellType(std::vector<Cell> v(int x)); //returns what type of cell it is
    void setTile(int x, int y, Cell*); //sets tile to type( inherited type)
    
    private:
    void drawCell(SDL_Renderer* renderer, int xpos, int ypos, int tilesize); //draw individual cell
    std::vector<Cell*> listCells; // vector of pointers to cells
    const int nRows,nCols;

};

#endif