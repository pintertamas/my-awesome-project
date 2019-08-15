#include "global.h"

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