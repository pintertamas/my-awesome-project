#include "global.h"

void setupBalls(){
    Balls = (Ball *) malloc(ballNumber * sizeof(Ball));

    for(int i=0; i<ballNumber; i++){
        Balls[i].visible = true;
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

void setupShip(){                                                                                                       //the ship is a 50x70 image
    ship.xsize = 50;
    ship.ysize = 70;
    ship.xpos = (float)screenWidth/2 - (float)ship.xsize/2;
    ship.ypos = (float)(screenHeight - ship.ysize);
    ship.speed = shipSpeed;
}

void setupBullet() {
    bullets = (Bullet **) malloc (bulletMax * sizeof(Bullet *));
    for(int i = 0; i < bulletMax; i++) {
        bullets[i] = (Bullet *) malloc(bulletPower * sizeof(Bullet));
    }
    for(int i = 0; i < bulletMax; i++) {
        for(int j = 0; j < bulletPower; j++) {
            bullets[i][j].xpos =
                    (float) (ship.xpos + (float) ship.xsize / 2 -
                    (bulletPower - 0.5) * 2 * bulletRadius + i * 4 * bulletRadius) + (float) bulletRadius;
            bullets[i][j].ypos = (float)(screenHeight - ship.ysize - bulletRadius * 3);
            bullets[i][j].visible = false;
        }
    }
}

void addBullet(float x, float y, float dy, int i) {
    bullets[i][0].xpos = x;
    bullets[i][0].ypos = y;
    bullets[i][0].speed = dy;
    bullets[i][0].visible = true;
}

void bulletTest() {
    //printf("%2f %2f\n", ship.xpos, ship.ypos);
    for(int i = 0; i < bulletMax; i++) {
        for(int j = 0; j < bulletPower; j++) {
            if(bullets[i][j].visible == true)
                printf("%d\n", bullets[i][j].visible);
        }
    }
}

void spawnBullet() {
    if(IsKeyPressed(KEY_SPACE)) {
        for (int i = 0; i < bulletPower; i++) {
            addBullet(
                    (float) (ship.xpos + (float) ship.xsize / 2 -
                    (bulletPower - 0.5) * 2 * bulletRadius + i * 4 * bulletRadius) + (float) bulletRadius,
                    (float)(screenHeight - ship.ysize - bulletRadius * 3), (float)bulletSpeed, i);
        }
    }
}

void renderBullet() {
    for(int i = 0; i < bulletPower; i++) {
        for(int j = 0; j < bulletPower; j++) {
            if(bullets[i][j].visible == true)
                DrawCircle((int)bullets[i]->xpos, (int)bullets[i]->ypos, (float)bulletRadius, BLACK);
        }
    }
}

void updateBullet() {
    for(int i = 0; i < bulletMax; i++) {
        for(int j = 0; j < bulletPower; j++) {
            if(bullets[i][j].visible == true)
                bullets[i][j].ypos -= (float)bulletSpeed;
        }
    }
}

void freeBullets() {
    for(int i = 0; i < bulletMax; i++) {
        for(int j = 0; j < bulletPower; j++) {
            if(bullets[i][j].ypos <= 0) {
                bullets[i][j].visible = false;
                //printf("%d, %d\n", i, j);
            }
        }
    }
}

void BulletBallCollision() {
    for(int i = 0; i < bulletMax; i++) {
        for(int j = 0; j < bulletPower; j++) {
            for(int k = 0; k < ballNumber; k++) {
                if(
                    bullets[i][j].visible == true && Balls[k].visible == true &&
                    sqrt(
                       pow( abs( (int)(bullets[i][j].ypos - Balls[k].ypos) ),2) +
                       pow( abs( (int)(bullets[i][j].xpos - Balls[k].xpos) ),2)) <=
                            bulletRadius + Balls[k].radius) {
                                Balls[k].HP /= 2;
                                bullets[i][j].visible = false;
                }
            }
        }
    }
}

/*
void setupBullet(){
    for(int i = 0; i < bulletMax; i++)
        bullets[i] = NULL;
}

void addBullet(float x, float y, float dy)
{
    int found = -1;
    for(int i = 0; i < bulletMax; i++)
    {
        if(bullets[i] == NULL)
        {
            found = i;
            break;
        }
    }

    if(found >= 0)
    {
        int i = found;
        bullets[i] = malloc(sizeof(Bullet));
        bullets[i]->xpos = x;
        bullets[i]->ypos = y;
        bullets[i]->speed = dy;
        DrawCircle((int)bullets[i]->xpos, (int)bullets[i]->ypos, bulletRadius, BLACK);
    }
}

void updateBullet(){
    for(int i = 0; i < bulletMax; i++) {
        if (bullets[i]->xpos < 0) {
            free(bullets[i]);
            bullets[i] = NULL;
        }
        //bullets[i]->ypos -= bullets[i]->speed;
        //DrawCircle((int)bullets[i]->xpos, (int)bullets[i]->ypos, bulletRadius, bullets[i]->color);
    //}
}

void spawnBullet(){
    if(IsKeyDown(KEY_SPACE))
        addBullet(ship.xpos + (float)ship.xsize/2, screenHeight - ship.ysize - 3*bulletRadius, 5);
}

void freeBullets() {
    for (int i = 0; i < bulletMax; i++) {
        free(bullets[i]);
        bullets[i] = NULL;
    }
}
*/

void pauseGame() {
    for(int i = 0; i < ballNumber; i++) {
        Balls[i].vx = 0;
        Balls[i].vy = 0;
        Balls[i].gravity = 0;
        ship.speed = 0;
    }
}

void resumeGame() {
    for(int i = 0; i < ballNumber; i++) {
        Balls[i].vx = 10;
        Balls[i].vy = 10;
        Balls[i].gravity = 1;
        ship.speed = shipSpeed;
    }
}

bool ShipBallCollision(){
    for (int i = 0; i < ballNumber; i++) {
        float d = Balls[i].ypos + (float)Balls[i].radius;
        if ((float)screenHeight - (float)ship.ysize/2 > d && d > (float)(screenHeight - ship.ysize)) {
            if (Balls[i].xpos > ship.xpos - (float) ship.xsize / 4 &&
                Balls[i].xpos < ship.xpos + (float) ship.xsize / 4) {
                //Balls[i].color = BLACK;
                //pauseGame();
                return true;
            }
        }else if((float)screenHeight - (float)ship.ysize/2 < d) {
            if (Balls[i].xpos > ship.xpos - (float) ship.xsize &&
                Balls[i].xpos < ship.xpos + (float) ship.xsize) {
                //Balls[i].color = BLACK;
                //pauseGame();
                return true;
            }
        } else return false;
    }
}

void ballbounce(Ball *ball, bool gravity){
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
        ball->vx *= (float).996;                                                                                               //slowing the ball down in the x axis
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

void applyPhysics_Coins(Ball *ball) {
    for(int i=0; i<ballNumber; i++) {
        ballbounce(&ball[i], true);
        collisionWall(&ball[i]);
    }
}

void moveShip() {
    if(IsKeyDown(KEY_LEFT))
        ship.xpos -= (float)ship.speed;
    if(ship.xpos < 0)
        ship.xpos = 0;
    if(IsKeyDown(KEY_RIGHT))
        ship.xpos += (float)ship.speed;
    if(ship.xpos > (float)(screenWidth - ship.xsize))
        ship.xpos = (float)(screenWidth - ship.xsize);
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