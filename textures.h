//
// Created by Tomi on 15/01/2019.
//

#ifndef FARMVILLE2_TEXTURES_H
#define FARMVILLE2_TEXTURES_H

#include "global.h"

typedef enum textureIndex{
    BACKGROUND, BALL
}textureIndex;

SDL_Texture *textures[2];
SDL_Surface *balance;
TTF_Font *font;

SDL_Texture *loadTexture(char *path);

SDL_Texture* getTexture(textureIndex index);
void loadImage();
void background();
void doRender();
void score();

#endif //FARMVILLE2_TEXTURES_H
