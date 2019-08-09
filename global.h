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
    float xpos;
    float ypos;

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
    Color color;
    int HP;
}Ball;

extern int ballNumber;
Ball *Balls;



#endif //HEADBALL_GLOBAL_H
