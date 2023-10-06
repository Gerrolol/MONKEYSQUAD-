#include "TextureLoader.h"

SDL_Texture* TextureLoader::loadTexture(SDL_Renderer* renderer, std::string filename){
    if (filename != "") {
        if (texturesLoaded.find(filename) != texturesLoaded.end()) {
            return texturesLoaded.find(filename)->second;
        }
        else {
            std::string filepath = "data//" + filename;
            SDL_Surface* surfaceTemp = SDL_LoadBMP(filepath.c_str());
            SDL_Texture* textureOutput = SDL_CreateTextureFromSurface(renderer, surfaceTemp);
            SDL_FreeSurface(surfaceTemp);

            if (textureOutput != nullptr) {//transparency
                SDL_SetTextureBlendMode(textureOutput, SDL_BLENDMODE_BLEND);
            
            //Add the texture to map
            texturesLoaded[filename] = textureOutput;
            return textureOutput;
            }
        }
    }
}

void TextureLoader::deallocateTextures(){
    while (!texturesLoaded.empty()) {
        if (texturesLoaded.begin()->second != nullptr)
            SDL_DestroyTexture(texturesLoaded.begin()->second);

        texturesLoaded.erase(texturesLoaded.begin());
    }
}