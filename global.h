#ifndef HEADBALL_GLOBAL_H
#define HEADBALL_GLOBAL_H

#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

extern int resolutionX;
extern int resolutionY;

extern int screenWidth;
extern int screenHeight;

extern int menu_screenWidth;
extern int menu_screenHeight;

extern Color BACKGROUND_COLOR;

typedef enum state {
    MENU, GAME, SETTINGS, SCORES
}state;

state gameState;

typedef struct Ship{
    double xpos;
    double ypos;
    int xsize;
    int ysize;
    int speed;
}Ship;

Ship ship;

Image textures[9];
Texture2D   shipTexture, menuBackground, background_mountain,
            startButton_simple, startButton_clicked,
            settingsButton_simple, settingsButton_clicked,
            scoresButton_simple, scoresButton_clicked;
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

extern clock_t shoot;
extern int shootDelay;
extern int bulletCount;                                                                                                 //number of bullets in one row
extern int bulletRadius;                                                                                                //size of the bullets
extern int bulletSpeed;                                                                                                 //the speed of the bullets

#endif //HEADBALL_GLOBAL_H