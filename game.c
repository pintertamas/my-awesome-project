#include "global.h"

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
        Balls[i].vy = (float)GetRandomValue(-10, 0);
        Balls[i].vx = (float)GetRandomValue(-5, 5);
        Balls[i].xpos = (float)GetRandomValue(Balls[i].radius, screenWidth - Balls[i].radius);
        Balls[i].ypos = (float)GetRandomValue(Balls[i].radius,screenHeight/2);
        Balls[i].gravity = 1;
        Balls[i].bounce = -1;
        printf("%2f, %2f, %2f, %2f, %d\n", Balls[i].xpos, Balls[i].ypos, Balls[i].vy, Balls[i].vx, Balls[i].radius);
    }
}

void setupShip(){                                                                                                       //the ship is a 50x70 image
    ship.xsize = 50;
    ship.ysize = 70;
    ship.xpos = (float)screenWidth/2 - (float)ship.xsize/2;
    ship.ypos = (float)screenHeight - (float)ship.ysize;
    ship.speed = 10;
}

void setupBullets(){
    bullets = (Bullet **) malloc(bulletPower * sizeof(Bullet *));


}

bool ShipBallCollision(){
    for (int i = 0; i < ballNumber; i++) {
        float d = Balls[i].ypos + (float)Balls[i].radius;
        if ((float)screenHeight - (float)ship.ysize/2 > d && d > (float)screenHeight - (float)ship.ysize) {
            if(Balls[i].xpos > ship.xpos - (float) ship.xsize / 4 &&
            Balls[i].xpos < ship.xpos + (float) ship.xsize / 4)
            return true;
            else return false;
        }else if((float)screenHeight - (float)ship.ysize/2 < d) {
            if (Balls[i].xpos > ship.xpos - (float) ship.xsize &&
                Balls[i].xpos < ship.xpos + (float) ship.xsize)
                return true;
            else return false;
        }
    }
}

void ballbounce(Ball *ball, bool gravity){
    ball->vy += ball->gravity;
    ball->ypos += ball->vy/10;
    if(ball->ypos > (float)screenHeight - (float)ball->radius)
    {
        ball->ypos = (float)screenHeight - (float)ball->radius;
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
    DrawCircle((int)ball->xpos,(int)ball->ypos,(float)ball->radius,ball->color);
    DrawText(FormatText("%d", ball->HP), (int)ball->xpos - ball->radius/2, (int)ball->ypos - ball->radius/2, 2*ball->radius/3, BLACK);
}

void collisionWall(Ball *ball){
    if(ball->xpos >= (float)screenWidth - (float)ball->radius){
        ball->xpos = (float)screenWidth -(float)ball->radius; ball->vx = -ball->vx;
    }
    if(ball->xpos <= (float)ball->radius){
        ball->xpos = (float)ball->radius; ball->vx = -ball->vx;
    }
    if(ball->ypos < (float)ball->radius){
        ball->ypos = (float)ball->radius; ball->vy = -ball->vy;
    }
}

void applyPhysics_Balls(Ball *ball){
    for(int i=0; i<ballNumber; i++){
        ballbounce(&ball[i], false);
        collisionWall(&ball[i]);
    }
}

void applyPhysics_Coins(Ball *ball){
    for(int i=0; i<ballNumber; i++){
        ballbounce(&ball[i], true);
        collisionWall(&ball[i]);
    }
}

void moveShip(){
    if(IsKeyDown(KEY_LEFT))
        ship.xpos -= (float)ship.speed;
    if(ship.xpos < 0)
        ship.xpos = 0;
    if(IsKeyDown(KEY_RIGHT))
        ship.xpos += (float)ship.speed;
    if(ship.xpos > (float)screenWidth - (float)ship.xsize)
        ship.xpos = (float)screenWidth - (float)ship.xsize;
}

void freeBalls(){
    for(int i=0;i<ballNumber;i++)
        free(&Balls[i]);
}