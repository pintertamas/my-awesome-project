#include "global.h"

void setupBullet() {
    bullets = (Bullet **) malloc (bulletMax * sizeof(Bullet *));
    for(int i = 0; i < bulletMax; i++) {
        bullets[i] = (Bullet *) malloc(bulletPower * sizeof(Bullet));
    }
    for(int i = 0; i < bulletMax; i++) {
        for(int j = 0; j < bulletPower; j++) {
            bullets[i][j].ypos = (float)(screenHeight - ship.ysize - bulletRadius * 3);
            bullets[i][j].visible = false;
        }
    }
}

void addBullet(float x, float y, float dy, int i) {
    for(int j = 0; j < bulletMax - 1; j++) {
        if( bullets[i][j].visible == false) {
            bullets[i][j].xpos = x;
            bullets[i][j].ypos = y;
            bullets[i][j].speed = dy;
            bullets[i][j].visible = true;
            break;
        }
    }
}

void spawnBullet() {
    if(IsKeyPressed(KEY_SPACE)) {
        bool isWholeLineReady = true;
        for(int i = 0; i < bulletMax; i++)
            for(int j = 0; j < bulletPower; j++)
                if(bullets[i][j].visible == true) {
                    isWholeLineReady = false;
                    break;
                }

        for (int i = 0; i < bulletPower; i++) {
            if(isWholeLineReady == true)
                addBullet(
                        (float) (ship.xpos + (float) ship.xsize / 2 -
                        (bulletPower - 0.5) * 2 * bulletRadius + i * 4 * bulletRadius) + (float) bulletRadius,
                        (float)(screenHeight - ship.ysize - bulletRadius * 3), (float)bulletSpeed, i);
        }
    }
}

void bulletTest() {
    for(int i = 0; i < bulletMax; i++) {
        for(int j = 0; j < bulletPower; j++) {
            if(bullets[i][j].visible == true)
                printf("%d\n", bullets[i][j].visible);
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
