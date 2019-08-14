#ifndef HEADBALL_GAME_H
#define HEADBALL_GAME_H

#include "global.h"

void BulletBallCollision();
void pauseGame();
void resumeGame();
bool ShipBallCollision();
void applyPhysics_Coins(Ball *ball);

#endif //HEADBALL_GAME_H