#include "global.h"

void loadImage(){
    textures[0] = LoadImage("Textures/ship.png");                                                                       // Loaded in CPU memory (RAM)
    ImageFormat(&textures[0], UNCOMPRESSED_R8G8B8A8);                                                                   // Format image to RGBA 32bit (required for texture update)
    shipTexture = LoadTextureFromImage(textures[0]);                                                                           // Image converted to texture, GPU memory (VRAM)
}

void renderMap(){
    DrawTexture(shipTexture, (int)ship.xpos, (int)ship.ypos, WHITE);
}