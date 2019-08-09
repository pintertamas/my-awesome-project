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

typedef struct Ball{
        float xpos;
        float ypos;
        float vy;
        float vx;
        float gravity;
        float bounce;
        int radius;
}Ball;

extern int ballNumber;
Ball *Balls;



#endif //HEADBALL_GLOBAL_H
