#ifndef MY_AWESOME_PROJECT_GAME_H
#define MY_AWESOME_PROJECT_GAME_H

#include "global.h"
#include "ball.h"

double **endGame;
bool isPaused;
void game ();
typedef enum STOPGAME { PAUSE, RESUME}StopGame;
int lifePoints;
bool inCollision;
bool ShipBallCollision ();
void BulletBallCollision ();
void endOfGame ();
void renderBackground();

#endif //MY_AWESOME_PROJECT_GAME_H