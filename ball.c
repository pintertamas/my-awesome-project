#include "global.h"

void setupBalls() {
    Balls = (Ball *) malloc(ballNumber * sizeof(Ball));

    for(int i=0; i<ballNumber; i++) {
        Balls[i].visible = true;
        int size = GetRandomValue(1,5);
        switch(size) {
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
        int d = GetRandomValue(0,1);
        if(d == 0)
            Balls[i].xpos = (float)Balls[i].radius;
        else
            Balls[i].xpos = (float)(screenWidth - Balls[i].radius);
        Balls[i].vx = 0;
        while(Balls[i].vx == 0)
            Balls[i].vx = (float)GetRandomValue(-5, +5);
        Balls[i].vy = (float)GetRandomValue(-10, 0);
        //Balls[i].xpos = GetRandomValue(Balls[i].radius, screenWidth - Balls[i].radius);
        Balls[i].ypos = (float)GetRandomValue(Balls[i].radius,screenHeight/2);
        Balls[i].gravity = (float)ballGravity;
        Balls[i].bounce = -1;
    }
}

void ballbounce(Ball *ball, bool gravity) {
    ball->vy += ball->gravity;
    ball->ypos += ball->vy/10;
    if(ball->ypos > (float)screenHeight - (float)ball->radius)
    {
        ball->ypos = (float)(screenHeight - ball->radius);
        if(gravity == true)
            ball->vy *= ball->bounce/5;
        else
            ball->vy *= ball->bounce;
    }

    ball->xpos += ball->vx;
    //---------------------
    //ball->vy *= .99;                                                                                                  //slowing down the ball int the y axis
    if(gravity == true) {
        ball->vx *= (float).996;                                                                                        //slowing the ball down in the x axis
    }
    //---------------------
    for(int i = 0; i < ballNumber; i++) {
        if(Balls[i].visible == true) {
            DrawCircle((int)ball->xpos,(int)ball->ypos, (float)ball->radius, ball->color);
            DrawText(FormatText ("%d", ball->HP), (int)ball->xpos - ball->radius / 2,
                     (int)ball->ypos - ball->radius/4, 2 * ball->radius / 3, BLACK);
        }
    }
}

void collisionWall(Ball *ball) {
    if(ball->xpos >= (float)(screenWidth - ball->radius)) {
        ball->xpos = (float)(screenWidth -ball->radius); ball->vx = -ball->vx;
    }
    if(ball->xpos <= (float)ball->radius) {
        ball->xpos = (float)ball->radius; ball->vx = -ball->vx;
    }
    if(ball->ypos < (float)ball->radius) {
        ball->ypos = (float)ball->radius; ball->vy = -ball->vy;
    }
}

void applyPhysics_Balls(Ball *ball) {
    for(int i=0; i<ballNumber; i++) {
        if(Balls[i].visible == true) {
            ballbounce(&ball[i], false);
            collisionWall(&ball[i]);
        }
    }
}

void updateBalls() {
    for(int i = 0; i < ballNumber; i++) {
        if(Balls[i].HP <= 64) {
            Balls[i].color = DARKGREEN;
            Balls[i].radius = 20;
        }
        if(Balls[i].HP > 64 && Balls[i].HP <= 128) {
            Balls[i].color = DARKBLUE;
            Balls[i].radius = 25;
        }
        if(Balls[i].HP > 128 && Balls[i].HP <= 256) {
            Balls[i].color = ORANGE;
            Balls[i].radius = 30;
        }
        if(Balls[i].HP > 256 && Balls[i].HP <= 512) {
            Balls[i].color = RED;
            Balls[i].radius = 35;
        }
        if(Balls[i].HP > 512 && Balls[i].HP <= 1024) {
            Balls[i].color = DARKPURPLE;
            Balls[i].radius = 40;
        }
    }
}

void freeBalls() {
    for(int i=0;i<ballNumber;i++)
        free(&Balls[i]);
}

void isBallAlive() {
    for(int i = 0; i < ballNumber; i++) {
        if(Balls[i].HP == 0)
            Balls[i].visible = false;
    }
}