#include "global.h"
#include "ship.h"
#include "textures.h"
#include "bullet.h"
#include "game.h"
#include "menu.h"

Bullet *bullets = NULL;
clock_t shoot;
int shootDelay = 69;
int shipSpeed = 10;                                                                                                     //the speed of the bullets
int bulletCount = 5;
int bulletRadius = 5;
int bulletSpeed = 15;
int bulletDamage = 1;

void freeList (Bullet *fromHere) {
    Bullet *cursor = fromHere;
    while (cursor->next != NULL) {
        Bullet *next = cursor->next;
        //free(&cursor);
        cursor = next;
    }
}

Bullet *list_prepend (Bullet *first, double xpos, double ypos, Color color) {
    Bullet *new;
    new = (Bullet*) malloc(sizeof(Bullet));
    new->xpos = xpos;
    new->ypos = ypos;
    new->color = color;
    new->visible = true;
    new->next = first;
    return new;
}

void spawnBullets () {
    double shipCenter = ship.xpos + (double)ship.xsize / 2;
    double leftPoint = (bulletCount - 0.5) * 2 * bulletRadius;


    if(IsKeyDown(KEY_SPACE) && (double)(clock() - shoot) >= shootDelay && lifePoints != 0) {
        //printf("%f\n", (double)(clock() - shoot));
        shoot = clock();

        for(int i = 0; i < bulletCount; i++) {
            bullets = list_prepend(
                    bullets,
                    shipCenter - leftPoint + i * 4 * bulletRadius + bulletRadius,
                    screenHeight - ship.ysize - bulletRadius * 3,
                    BLACK
                    );
            //printf("%d ", (int)bullets->xpos);
            //DrawCircle(bullets->xpos, bullets->ypos, bulletRadius, bullets->color);
        }
    }
}

void updateBullets () {
    Bullet *cursor;
        for(cursor = bullets; cursor != NULL; cursor = cursor->next) {
            cursor->ypos -= bulletSpeed;
        }
}

void renderBullets () {
    Bullet *cursor;
        for(cursor = bullets; cursor != NULL; cursor = cursor->next) {
            if(cursor->ypos >= bulletRadius) {

                switch(background) {
                    case FOREST:
                        DrawTexture(brownBullet, cursor->xpos, cursor->ypos, WHITE);
                        break;
                    case MOUNTAINS:
                        DrawTexture(redBullet, cursor->xpos, cursor->ypos, WHITE);
                        break;
                    case JAPAN:
                        DrawTexture(starBullet, cursor->xpos, cursor->ypos, WHITE);
                        break;
                    case SPACE:
                        DrawTexture(greenBullet, cursor->xpos, cursor->ypos, WHITE);
                        break;
                    default:
                        break;
                }
            }
        }
}