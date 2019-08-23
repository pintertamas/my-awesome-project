#include "global.h"

bool ShipBallCollision (){
    for (int i = 0; i < ballNumber; i++) {
        double d = Balls[i].ypos + Balls[i].radius;
        if (screenHeight - (double)ship.ysize/2 > d && d > (screenHeight - ship.ysize)) {
            if (Balls[i].xpos > ship.xpos - (double) ship.xsize / 4 &&
                Balls[i].xpos < ship.xpos + (double) ship.xsize / 4) {
                //Balls[i].color = BLACK;
                //pauseGame();
                return true;
            }
        }else if((double)screenHeight - (double)ship.ysize/2 < d) {
            if (Balls[i].xpos > ship.xpos - (double) ship.xsize &&
                Balls[i].xpos < ship.xpos + (double) ship.xsize) {
                //Balls[i].color = BLACK;
                //pauseGame();
                return true;
            }
        }
    }
    return false;
}

void BulletBallCollision () {
    Bullet *cursor;
    for(cursor = bullets; cursor != NULL; cursor = cursor->next) {
        for(int i = 0; i < ballNumber; i++) {
            int a_square = pow(abs((int)cursor->xpos - (int)Balls[i].xpos), 2);
            int b_square = pow(abs((int)cursor->ypos - (int)Balls[i].ypos), 2);
            if (sqrt(a_square + b_square) < bulletRadius + Balls[i].radius) {
                Balls[i].HP -= 1;
            }
            if(Balls[i].HP == 0)
                Balls[i].visible = 0;
        }
    }
}

void pauseGame () {
    for(int i = 0; i < ballNumber; i++) {
        Balls[i].vx = 0;
        Balls[i].vy = 0;
        Balls[i].gravity = 0;
        ship.speed = 0;
    }
}

void resumeGame () {
    for(int i = 0; i < ballNumber; i++) {
        Balls[i].vx = 10;
        Balls[i].vy = 10;
        Balls[i].gravity = 1;
        ship.speed = shipSpeed;
    }
}