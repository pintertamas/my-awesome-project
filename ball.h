#ifndef MY_AWESOME_PROJECT_BALL_H
#define MY_AWESOME_PROJECT_BALL_H

Font font;

typedef struct Ball{
    double xpos;
    double ypos;
    double vy;
    double vx;
    double gravity;
    double bounce;
    int radius;
    int HP;
    Color color;
    bool visible;
    struct Ball *next;
}Ball;

Ball *Balls;

extern int ballGravity;                                                                                                 //the strengty of the gravity
extern int ballNumber;                                                                                                  //number of balls on the playfield at a time

void setupBalls ();
void ballbounce (Ball *ball, bool gravity);
void collisionWall (Ball *ball);
void updateBalls ();
void isBallAlive ();
bool IsThereAnyBall ();
void applyPhysics_Balls(Ball *ball);

#endif //MY_AWESOME_PROJECT_BALL_H