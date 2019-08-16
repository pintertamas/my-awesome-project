#include "global.h"

//(float) (ship.xpos + (float) ship.xsize / 2 - (bulletPower - 0.5) * 2 * bulletRadius + i * 4 * bulletRadius) + (float) bulletRadius
//(float)(screenHeight - ship.ysize - bulletRadius * 3)

void freeList (Bullet *first) {
    Bullet *cursor = first;
    while (cursor != NULL) {
        Bullet *next = cursor->next;
        free(cursor);
        cursor = next;
    }
}

Bullet *list_prepend(Bullet *first, double xpos, double ypos, Color color) {
    Bullet *new;
    new = (Bullet*) malloc(sizeof(Bullet));
    new->next = first;
    new->xpos = xpos;
    new->ypos = ypos;
    new->color = BLACK;
    new->visible = true;
    new->next = NULL;
    printf("%d ", (int)new->xpos);
    //DrawCircle(new->xpos, new->ypos, bulletRadius, BLACK);
    return new;
}

void updateBullets (Bullet *first) {
    Bullet *cursor;
    for(cursor = first; cursor != NULL; cursor = cursor->next) {
        cursor->ypos -= bulletSpeed;
        DrawCircle(cursor->xpos, cursor->ypos, bulletRadius, BLACK);
        if(cursor->ypos < 0) {
            freeList(cursor);
            printf("%d ", (int) cursor->ypos);
            break;
        }
    }
}

void spawnBullet (Bullet *first) {
    double shipCenter = ship.xpos + (double)ship.xsize / 2;
    double leftPoint = (bulletCount - 0.5) * 2 * bulletRadius;

    if(IsKeyDown(KEY_SPACE)) {
        printf("space\n");
        for(int i = 0; i < bulletCount; i++) {
            first = list_prepend(
                    first,
                    shipCenter - leftPoint + i * 4 * bulletRadius + bulletRadius,
                    screenHeight - ship.ysize - bulletRadius * 3,
                    BLACK
                    );
        }
    }
}

void renderBullets (Bullet *first) {
    Bullet *cursor;
    for(cursor = first; cursor != NULL; cursor = cursor->next) {
        DrawCircle(cursor->xpos, cursor->ypos, bulletRadius, BLACK);
        printf("%d ", (int) cursor->xpos);
    }
}