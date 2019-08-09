#include "global.h"
#include "game.h"

void setupBalls(){
    Balls = (Ball *) malloc(ballNumber * sizeof(Ball));

    for(int i=0; i<ballNumber; i++){
        int size = GetRandomValue(1,5);
        switch(size){
            case 1:
                Balls[i].radius = 20;
                Balls[i].color = DARKGREEN;
                Balls[i].HP = 64;
                break;
            case 2:
                Balls[i].radius = 25;
                Balls[i].color = DARKBLUE;
                Balls[i].HP = 128;
                break;
            case 3:
                Balls[i].radius = 30;
                Balls[i].color = ORANGE;
                Balls[i].HP = 256;
                break;
            case 4:
                Balls[i].radius = 35;
                Balls[i].color = RED;
                Balls[i].HP = 512;
                break;
            case 5:
                Balls[i].radius = 40;
                Balls[i].color = DARKPURPLE;
                Balls[i].HP = 1024;
                break;
            default: ;
        }
        Balls[i].vy = GetRandomValue(-10, 0);
        Balls[i].vx = GetRandomValue(-5, 5);
        Balls[i].xpos = GetRandomValue(Balls[i].radius, screenWidth - Balls[i].radius);
        Balls[i].ypos = GetRandomValue(Balls[i].radius,screenHeight/2);
        Balls[i].gravity = 1;
        Balls[i].bounce = -1;
        printf("%2f, %2f, %2f, %2f, %d\n", Balls[i].xpos, Balls[i].ypos, Balls[i].vy, Balls[i].vx, Balls[i].radius);
    }
}

void ballbounce(Ball *ball){
    ball->vy += ball->gravity;
    ball->ypos += ball->vy/5;
    if(ball->ypos > screenHeight - ball->radius)
    {
        ball->ypos = screenHeight - ball->radius;
        ball->vy *= ball->bounce;
    }

    ball->xpos += ball->vx;
    //---------------------
    //ball->vx*=.996;                                                              //slowing the ball down in the x axis
    //ball->vy*=.995;                                                             //slowing down the ball int the y axis
    //---------------------
    DrawCircle((int)ball->xpos,(int)ball->ypos,ball->radius,ball->color);
    DrawText(FormatText("%d", ball->HP), (int)ball->xpos - ball->radius, (int)ball->ypos - ball->radius/2, ball->radius, BLACK);

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