#include "Map.h"
Map::Map(){};

Map::Map(SDL_Renderer* renderer, int nCellCols, int nCellRows):
    nRows(nCellRows),
    nCols(nCellCols){ 
    std::cout<<"loading textures"<<std::endl;
    textureWater = TextureLoader::loadTexture(renderer,"Water.bmp");
    textureLand = TextureLoader::loadTexture(renderer,"Grass.bmp");
    texturePath = TextureLoader::loadTexture(renderer,"Path.bmp");

    int mapSize = nRows * nCols;
    listCells.resize(mapSize, nullptr);
}


void Map::draw(SDL_Renderer *renderer, int tilesize){
    for(int i =0; i<listCells.size();i++){
        drawCell(renderer,i,tilesize);
    }
}

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
    SDL_Rect rect = {((pos%16))*tilesize, (pos/16)*tilesize,tilesize,tilesize};
    SDL_RenderCopy(renderer, textureSelected,NULL, &rect);
}

void Map::setCell(int pos, char celltype){
    switch (celltype){
        case 'L':
            delete listCells[pos];
            newCell = new Land;
            break;
        case 'P':
            delete listCells[pos];
            newCell = new path;
            break;
        case 'W':
            delete listCells[pos];
            newCell = new Water;
            break;
    }
    listCells[pos] = newCell;
}