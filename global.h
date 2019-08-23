#ifndef HEADBALL_GLOBAL_H
#define HEADBALL_GLOBAL_H

#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

extern int screenWidth;
extern int screenHeight;

typedef struct Ship{
    double xpos;
    double ypos;
    int xsize;
    int ysize;
    int speed;
}Ship;

Ship ship;

Image textures[1];
Texture2D shipTexture;
extern int shipSpeed;                                                                                                   //the speed of the ship

typedef struct Ball{
    double xpos;
    double ypos;
    double vy;
    double vx;
    double gravity;
    double bounce;
    int radius;
    int HP;
    Color color;
    bool visible;
}Ball;

Ball *Balls;

extern int ballGravity;                                                                                                 //the strengty of the gravity
extern int ballNumber;                                                                                                  //number of balls on the playfield at a time

typedef struct Bullet{
    double xpos;
    double ypos;
    Color color;
    bool visible;
    struct Bullet *next;
}Bullet;

extern Bullet *bullets;

extern int bulletCount;                                                                                                 //number of bullets in one row
extern int bulletRadius;                                                                                                //size of the bullets
extern int bulletSpeed;                                                                                                 //the speed of the bullets

#endif //HEADBALL_GLOBAL_H