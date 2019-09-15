#ifndef MY_AWESOME_PROJECT_GAME_H
#define MY_AWESOME_PROJECT_GAME_H

#include "ball.h"
#include "bullet.h"

double **endGame;
bool isPaused;
void game ();
typedef enum StopGame { PAUSE, RESUME}StopGame;
void stopGame(StopGame stopTheGame);
int lifePoints;
bool inCollision;
bool ShipBallCollision (Ball *head);
void BulletBallCollision (Ball *ball_head, Bullet *bullet_head);
void endOfGame ();
void renderBackground();

#endif //MY_AWESOME_PROJECT_GAME_H