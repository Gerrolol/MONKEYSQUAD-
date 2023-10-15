#include "TextureLoader.h"
#include <iostream>
//creates the map of loaded textures
std::unordered_map<std::string, SDL_Texture*> TextureLoader::texturesLoaded;
SDL_Texture* TextureLoader::loadTexture(SDL_Renderer* renderer, std::string filename){
    //makes sure the string is not empty to avoid errors
    if (filename != "") {
        //checks if texture has already been created and returns if already created
        auto found = texturesLoaded.find(filename);
        if (found != texturesLoaded.end()) {
            return found->second;
        }
        else {
            //creates filepath and copies that as a surface
            std::string filepath = "data/" + filename;
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
    return nullptr;
}
//deallocates the textures
void TextureLoader::deallocateTextures(){
    while (texturesLoaded.empty()== false) {
        auto thing = texturesLoaded.begin();
        if (thing->second != nullptr)
            SDL_DestroyTexture(thing->second);

        texturesLoaded.erase(thing);
    }
}