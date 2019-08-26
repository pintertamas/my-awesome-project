#ifndef HEADBALL_TEXTURES_H
#define HEADBALL_TEXTURES_H

typedef struct Ship{
    double xpos;
    double ypos;
    int xsize;
    int ysize;
    int speed;
}Ship;

Ship ship;

void setupShip();
void moveShip();
void renderShip();

#endif //HEADBALL_TEXTURES_H