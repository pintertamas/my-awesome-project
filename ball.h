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

extern Ball *balls;
extern int ballNumber;                                                                                                  //number of balls on the playfield at a time
extern int ballNumber_current;

void spawnBall ();
void setupBalls ();
void freeList_ball ();
void ballBounce (Ball *ball, bool gravity);
void collisionWall (Ball *head);
void updateBalls (Ball *head);
void isBallAlive (Ball *head);
void applyPhysics_Balls (Ball *head);
void renderBalls ();

#endif //MY_AWESOME_PROJECT_BALL_H