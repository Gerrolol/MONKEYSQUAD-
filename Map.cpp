#include "Map.h"
Map::Map(){};
//on initialisation creates the textures needed and sets variables.
Map::Map(SDL_Renderer* renderer, int nCellCols, int nCellRows):
    nRows(nCellRows),
    nCols(nCellCols){ 
    std::cout<<"loading textures"<<std::endl;
    textureWater = TextureLoader::loadTexture(renderer,"Water.bmp");
    textureLand = TextureLoader::loadTexture(renderer,"Grass.bmp");
    texturePath = TextureLoader::loadTexture(renderer,"Path.bmp");

    textureDart = TextureLoader::loadTexture(renderer,"Dart.bmp");
    textureSniper = TextureLoader::loadTexture(renderer,"Sniper.bmp");
    textureCannon = TextureLoader::loadTexture(renderer,"Cannon.bmp");

    int mapSize = nRows * nCols;
    listCells.resize(mapSize, nullptr);
}

//loops through each cell and runs the drawcell command
void Map::draw(SDL_Renderer *renderer, int tilesize){
    for(int i =0; i<listCells.size();i++){
        drawCell(renderer,i,tilesize);
    }
}
//checks the cell type to know what texture to use
void Map::drawCell(SDL_Renderer* renderer, int pos, int tilesize){
    SDL_Texture* textureSelected = textureLand;
    if(listCells[pos]->getType() == 'L'){
        textureSelected = textureLand;
    }
    else if(listCells[pos]->getType() == 'W'){
        textureSelected = textureWater;
    }
    else if(listCells[pos]->getType() == 'P'){
        textureSelected = texturePath;
    }
    if(listCells[pos]->getType() == 'D'){
        textureSelected = textureDart;
    }
    else if(listCells[pos]->getType() == 'C'){
        textureSelected = textureCannon;
    }
    else if(listCells[pos]->getType() == 'S'){
        textureSelected = textureSniper;
    }
    //renders the texture in correct position and size
    SDL_Rect rect = {((pos%16))*tilesize, (pos/16)*tilesize,tilesize,tilesize};
    SDL_RenderCopy(renderer, textureSelected,NULL, &rect);
}

//checks for what type of cell to set to, deletes the old cell at location then creates new cell of desired type.
void Map::setCell(int pos, char celltype){
    int xVal,yVal = 0;
    switch (celltype){
        case 'L':
            delete listCells[pos];
            newCell = new Land;
            break;
        case 'P':
            delete listCells[pos];
            newCell = new pathTile;
            break;
        case 'W':
            delete listCells[pos];
            newCell = new Water;
            break;
        case 'D':
            delete listCells[pos];
            xVal = pos%16;
            xVal = xVal*48 -24;
            yVal = (pos/16)+1;
            yVal = yVal*48 - 24;
            newCell = new Dart(xVal, yVal);
            break;
        case 'S':
            delete listCells[pos];
            newCell = new Sniper((pos%16)*48 - 24,((pos/16)+1)*48 -24);
            break;
        case 'C':
            delete listCells[pos];
            newCell = new Cannon((pos%16)*48 - 24,((pos/16)+1)*48 -24);
            break;
    }
    listCells[pos] = newCell;
}