#include "global.h"
#include "ship.h"
#include "textures.h"

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

void renderShip(){
    DrawTexture(shipTexture, (int)ship.xpos, (int)ship.ypos, WHITE);
}