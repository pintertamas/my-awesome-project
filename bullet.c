#include "global.h"

void freeList (Bullet *fromHere) {
    Bullet *cursor = fromHere;
    while (cursor->next != NULL) {
        Bullet *next = cursor->next;
        free(cursor);
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


    if(IsKeyDown(KEY_SPACE) && (double)(clock() - shoot) >= shootDelay) {
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
        if(cursor->ypos >= bulletRadius)
            DrawCircle(cursor->xpos, cursor->ypos, bulletRadius, BLACK);
    }
}