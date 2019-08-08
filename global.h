//
// Created by Tomi on 15/01/2019.
//

#ifndef HEADBALL_GLOBAL_H
#define HEADBALL_GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
SDL_Window *window;
SDL_Renderer *renderer;

typedef struct Ball{
    int x;
    int y;
    int r;
    int vx;
    int vy;
}Ball;
Ball ball;

typedef struct Player{
    int cx, cy, cr;
    int rx, ry;

}Player;

int mouseX, mouseY;
extern int speedX, speedY;
extern int radius;

#endif //HEADBALL_GLOBAL_H
