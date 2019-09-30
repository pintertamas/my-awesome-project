#include "global.h"
#include "player.h"
#include "textures.h"
#include "menu.h"

int playerSpeed = 10;                                                                                                     //the speed of the bullets

void setupPlayer(){                                                                                                       //the player is a 50x70 image
    player.xsize = 50;
    player.ysize = 70;
    player.xpos = (float)screenWidth/2 - (float)player.xsize/2;
    player.ypos = (float)(screenHeight - player.ysize);
    player.speed = playerSpeed;
}

void movePlayer() {
    if(player_isAlive) {
        if (IsKeyDown(KEY_LEFT))
            player.xpos -= (float) player.speed;
        if (player.xpos < 0)
            player.xpos = 0;
        if (IsKeyDown(KEY_RIGHT))
            player.xpos += (float) player.speed;
        if (player.xpos > (float) (screenWidth - player.xsize))
            player.xpos = (float) (screenWidth - player.xsize);
    }
}

void renderPlayer(){

    switch (background) {
        case FOREST:
            DrawTexture(car, (int)player.xpos, (int)player.ypos, WHITE);
            break;
        case MOUNTAINS:
            DrawTexture(car, (int)player.xpos, (int)player.ypos, WHITE);
            break;
        case JAPAN:
            DrawTexture(ninja, (int)player.xpos, (int)player.ypos, WHITE);
            break;
        case SPACE:
            DrawTexture(spaceShip, (int)player.xpos, (int)player.ypos, WHITE);
            break;
        default:
            break;
    }
}
