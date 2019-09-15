#ifndef HEADBALL_TEXTURES_H
#define HEADBALL_TEXTURES_H

typedef struct Player{
    double xpos;
    double ypos;
    int xsize;
    int ysize;
    int speed;
}Player;

Player player;

extern int playerSpeed;                                                                                                   //the speed of the player

void setupPlayer();
void movePlayer();
void renderPlayer();

#endif //HEADBALL_TEXTURES_H