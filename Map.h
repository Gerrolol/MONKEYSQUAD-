#ifndef MAP_H
#define MAP_H
#include <vector>
#include "cell.h"
#include "SDL2/SDL.h"
#include <string>
#include <iostream>
#include "TextureLoader.h"
#include "pathTile.h"
#include "Land.h"
#include "water.h"

class Map{
    public:
    Map();
    Map(SDL_Renderer* renderer, int nCellRows, int nCellCols);
    void draw(SDL_Renderer *renderer, int tilesize); //draws whole map
    void setCell(int pos, char celltype); //sets cell to type( inherited type)
    
    private:
    void drawCell(SDL_Renderer* renderer, int pos, int tilesize); //draw individual cell
    std::vector<Cell*> listCells; // vector of cells
    int nRows,nCols;
    Cell* newCell;

    SDL_Texture *textureWater = nullptr,
    *texturePath = nullptr,
    *textureLand = nullptr,
    
    *textureDart = nullptr,
    *textureCannon = nullptr,
    *textureSniper = nullptr;

};
#endif