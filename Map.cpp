#include "Map.h"

Map::Map(SDL_Renderer* renderer, int nCellRows, int nCellCols):
    nRows(nCellRows),
    nCols(nCellCols){ 
    
}

void draw();

std::string returnCellType(std::vector<Cell> v(int x)){
    
}

void setTile(int x, int y, Cell*);