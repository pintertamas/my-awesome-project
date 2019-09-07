#ifndef MY_AWESOME_PROJECT_GAME_H
#define MY_AWESOME_PROJECT_GAME_H

#include "global.h"
#include "ball.h"

void game ();
typedef enum STOPGAME { PAUSE, RESUME}STOPGAME;
STOPGAME stopTheGame;
int lifePoints;
bool ShipBallCollision ();
void BulletBallCollision ();
void endOfGame ();
void pauseGame ();
void resumeGame ();
void renderBackground();

#endif //MY_AWESOME_PROJECT_GAME_H