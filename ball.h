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
    bool visible;
    struct Ball *next;
}Ball;

extern Ball *balls;

typedef struct BallProperties{
    int ballNumber;                                                                                             //number of balls on the playfield at a time
    int ballNumber_current;
    int balls_destroyed;
    int damageDealt;
}BallProperties;
BallProperties ballProps;

void spawnBall ();
void freeList_ball ();
Ball *freeBalls_dead (Ball *head);
void ballBounce (Ball *ball, bool gravity);
void collisionWall (Ball *head);
void updateBalls (Ball *head);
void applyPhysics_Balls (Ball *head);
void renderBalls ();

#endif //MY_AWESOME_PROJECT_BALL_H