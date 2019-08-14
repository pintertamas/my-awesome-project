#ifndef HEADBALL_GAME_H
#define HEADBALL_GAME_H

#include "global.h"

void setupBalls();
void setupShip();
void setupBullet();
void addBullet(float x, float y, float dy, int i);
void spawnBullet();
void renderBullet();
void updateBullet();
void freeBullets();
void BulletBallCollision();
void pauseGame();
void bulletTest();
bool ShipBallCollision();
void applyPhysics_Balls(Ball *ball);
void applyPhysics_Coins(Ball *ball);
void moveShip();
void freeBalls();
void isBallAlive();

#endif //HEADBALL_GAME_H