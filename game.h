#ifndef MY_AWESOME_PROJECT_GAME_H
#define MY_AWESOME_PROJECT_GAME_H

#include "ball.h"
#include "bullet.h"

clock_t roundStart;
clock_t roundEnd;
clock_t damageTime;
bool isPaused;

typedef struct Pause{
    double vx;
    double vy;
    double gravity;
    int playerSpeed;
    int bulletSpeed;
    int bulletDamage;
}Pause;
Pause *pauseResume;

void setupBackupArray ();
void freeBackupArray ();
bool isPaused;
void game ();
typedef enum StopGame { PAUSE, RESUME}StopGame;
void stopGame(StopGame stopTheGame);
int lifePoints;
bool inCollision;
bool playerBallCollision (Ball *head);
void BulletBallCollision (Ball *ball_head, Bullet *bullet_head);
void renderBackground();

#endif //MY_AWESOME_PROJECT_GAME_H