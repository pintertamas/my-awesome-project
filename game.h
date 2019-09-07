#ifndef MY_AWESOME_PROJECT_GAME_H
#define MY_AWESOME_PROJECT_GAME_H

#include "global.h"
#include "ball.h"

void game ();
typedef enum STOPGAME { PAUSE, RESUME}StopGame;
StopGame stopTheGame;
int lifePoints;
bool inCollision;
bool ShipBallCollision ();
void BulletBallCollision ();
void endOfGame ();
void pauseGame ();
void resumeGame ();
void renderBackground();

#endif //MY_AWESOME_PROJECT_GAME_H