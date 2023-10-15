#include "Map.h"
Map::Map(){};

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
    if(listCells[pos]->getType() == 'D'){
        textureSelected = textureDart;
    }
    else if(listCells[pos]->getType() == 'C'){
        textureSelected = textureCannon;
    }
    else if(listCells[pos]->getType() == 'S'){
        textureSelected = textureSniper;
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
            newCell = new pathTile;
            break;
        case 'W':
            delete listCells[pos];
            newCell = new Water;
            break;
        case 'D':
            delete listCells[pos];
            newCell = new Dart((pos%16)*48 - 24,(pos/16)*48 -24);
            break;
        case 'S':
            delete listCells[pos];
            newCell = new Sniper((pos%16)*48 - 24,(pos/16)*48 -24);
            break;
        case 'C':
            delete listCells[pos];
            newCell = new Cannon((pos%16)*48 - 24,(pos/16)*48 -24);
            break;
    }
    listCells[pos] = newCell;
}