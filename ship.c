#include "global.h"

void setupShip(){                                                                                                       //the ship is a 50x70 image
    ship.xsize = 50;
    ship.ysize = 70;
    ship.xpos = (float)screenWidth/2 - (float)ship.xsize/2;
    ship.ypos = (float)(screenHeight - ship.ysize);
    ship.speed = shipSpeed;
}

void moveShip() {
    if(IsKeyDown(KEY_LEFT))
        ship.xpos -= (float)ship.speed;
    if(ship.xpos < 0)
        ship.xpos = 0;
    if(IsKeyDown(KEY_RIGHT))
        ship.xpos += (float)ship.speed;
    if(ship.xpos > (float)(screenWidth - ship.xsize))
        ship.xpos = (float)(screenWidth - ship.xsize);
}

void loadImage(){
    textures[0] = LoadImage("Textures/ship.png");                                                                       // Loaded in CPU memory (RAM)
    ImageFormat(&textures[0], UNCOMPRESSED_R8G8B8A8);                                                                   // Format image to RGBA 32bit (required for texture update)
    shipTexture = LoadTextureFromImage(textures[0]);                                                                           // Image converted to texture, GPU memory (VRAM)
}

void renderShip(){
    DrawTexture(shipTexture, (int)ship.xpos, (int)ship.ypos, WHITE);
}