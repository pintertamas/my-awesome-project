#ifndef HEADBALL_GAME_H
#define HEADBALL_GAME_H

#include "global.h"

void setupBalls();
void setupShip();
void setupBullets();
bool ShipBallCollision();
void applyPhysics_Balls(Ball *ball);
void applyPhysics_Coins(Ball *ball);
void moveShip();
void freeBalls();

#endif //HEADBALL_GAME_H