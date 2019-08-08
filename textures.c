//
// Created by Tomi on 15/01/2019.
//

#include "textures.h"
#include "global.h"

// initializing pictures
SDL_Texture *loadTexture(char *path) {
    SDL_Texture *texture = NULL;
    SDL_Surface *image = IMG_Load(path);

    if (NULL == image) {
        printf("Error1: %s\n", SDL_GetError());
    } else {
        texture = SDL_CreateTextureFromSurface(renderer, image);

        if (NULL == texture) {
            printf("Error2: %s\n", SDL_GetError());
        }
        SDL_FreeSurface(image);
    }
    return texture;
}

SDL_Texture *getTexture(textureIndex index) {
    return textures[index];                                                                                             // visszaadja a textúrát index alapján
}

void loadImage()                                                                                                        // ÚJABB KÉP FELTÖLTÉSE UTÁN A TÖMB MÉRETÉT IS NÖVELNI KELL!
{
    textures[0] = loadTexture("Textures/headball_bg.jpg");
    textures[1] = loadTexture("Textures/soccerball.png");
}

void background() {
    SDL_Rect background = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(renderer, textures[0], NULL, &background);
}

void doRender() {

    // goalline
    for(int i=0; i<SCREEN_HEIGHT; i++)
    {
        SDL_RenderDrawPoint(renderer, 40, i);
        SDL_RenderDrawPoint(renderer, 660, i);
    }
    for(int i=0;i<700;i++)
    {
        SDL_RenderDrawPoint(renderer, i, 404);
    }
}