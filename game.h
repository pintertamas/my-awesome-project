//
// Created by Tomi on 15/01/2019.
//

#ifndef HEADBALL_GAME_H
#define HEADBALL_GAME_H

#include "global.h"

int init();
void eventHandler(SDL_Event event);
bool isInside(int x0, int y0);

void drawBall(int x0, int y0, int radius);
void moveBall(Ball *ball);



#endif //HEADBALL_GAME_H
