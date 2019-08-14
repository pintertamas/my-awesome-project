#ifndef MY_AWESOME_PROJECT_BALL_H
#define MY_AWESOME_PROJECT_BALL_H

void setupBalls();
void ballbounce(Ball *ball, bool gravity);
void collisionWall(Ball *ball);
void freeBalls();
void isBallAlive();
void applyPhysics_Balls(Ball *ball);

#endif //MY_AWESOME_PROJECT_BALL_H
