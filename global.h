#ifndef HEADBALL_GLOBAL_H
#define HEADBALL_GLOBAL_H
#define bulletMax 1000

#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

extern int screenWidth;
extern int screenHeight;

Image textures[1];
Texture2D shipTexture;

typedef struct Ship{
    float xpos;
    float ypos;
    int xsize;
    int ysize;
    int speed;
}Ship;

Ship ship;

typedef struct Ball{
    float xpos;
    float ypos;
    float vy;
    float vx;
    float gravity;
    float bounce;
    int radius;
    int HP;
    Color color;
}Ball;

Ball *Balls;

typedef struct Bullet{
    float xpos;
    float ypos;
    float speed;
    Color color;
    bool visible;
}Bullet;

Bullet **bullets;

extern int shipSpeed;                                                                                                 //the speed of the bullets
extern int ballGravity;
extern int bulletRadius;                                                                                                //size of the bullets
extern int bulletPower;                                                                                                 //number of bullets in one row
extern int bulletSpeed;                                                                                                 //the speed of the bullets

extern int ballNumber;

#endif //HEADBALL_GLOBAL_H
