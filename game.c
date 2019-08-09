#include "global.h"
#include "game.h"

void setupBalls(){
    Balls = (Ball *) malloc(ballNumber * sizeof(Ball));

    for(int i=0; i<ballNumber; i++){
        Balls[i].radius = GetRandomValue(10,20);
        Balls[i].xpos = GetRandomValue(Balls[i].radius, screenWidth - Balls[i].radius);
        Balls[i].ypos = GetRandomValue(100,screenHeight/2);
        Balls[i].vy = GetRandomValue(-30, 0);
        Balls[i].vx = GetRandomValue(-10, 10);
        Balls[i].gravity = 0.98;
        Balls[i].bounce = -1;
        printf("%2f, %2f, %2f, %2f, %d\n", Balls[i].xpos, Balls[i].ypos, Balls[i].vy, Balls[i].vx, Balls[i].radius);
    }
}

void ballbounce(Ball *ball){
    ball->vy += ball->gravity;
    ball->ypos += ball->vy;
    if(ball->ypos > screenHeight - ball->radius)
    {
        ball->ypos = screenHeight - ball->radius;
        ball->vy *= ball->bounce;
    }

    ball->xpos += ball->vx;


    DrawCircle((int)ball->xpos,(int)ball->ypos,10,MAROON);
}

void collisionWall(Ball *ball){
    if(ball->xpos >= screenWidth - ball->radius){
        ball->xpos = screenWidth -ball->radius; ball->vx = -ball->vx;
    }
    if(ball->xpos <= ball->radius){
        ball->xpos = ball->radius; ball->vx = -ball->vx;
    }
    if(ball->ypos < ball->radius){
        ball->ypos = ball->radius; ball->vy = -ball->vy;
    }
}

void applyPhysics(){
    for(int i=0; i<ballNumber; i++){
        ballbounce(&Balls[i]);
        collisionWall(&Balls[i]);
    }
}