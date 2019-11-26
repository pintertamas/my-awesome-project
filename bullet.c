#include "global.h"
#include "player.h"
#include "textures.h"
#include "bullet.h"
#include "menu.h"
#include "game.h"
#include "debugmalloc.h"

Bullet *bullets = NULL;

void freeList_bullet () {
    Bullet *tmp;
    while (bullets != NULL) {
        tmp = bullets;
        bullets = bullets->next;
        free(tmp);
    }
}

Bullet* freeBullets_outside (Bullet *head) {
    while (head != NULL) {
        if (head->ypos < 0) {
            Bullet* tmp = head;
            head = head->next;
            free(tmp);
        } else {
            break;
        }
    }
    return head;
}

Bullet *list_append_bullet (Bullet *head, double xpos, double ypos) {
    Bullet *new;
    new = (Bullet*) malloc(sizeof(Bullet));
    new->xpos = xpos;
    new->ypos = ypos;
    new->visible = true;
    new->next = NULL;

    if(head == NULL) {
        return new;
    }

    Bullet *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new;
    return head;
}

void spawnBullets () {
    int gap = 4;
    double playerCenter = player.xpos + (double)player.xsize / 2;
    double leftPoint = bulletProps.bulletCount * bulletProps.bulletRadius + ((bulletProps.bulletCount - 1) / 2) * gap;

    if (IsKeyDown(KEY_SPACE) && (double)(clock() - bulletProps.shoot) >= bulletProps.shootDelay && player_isAlive && !isPaused) {
        bulletProps.shoot = clock();

        for(int i = 0; i < bulletProps.bulletCount; i++) {
            bullets = list_append_bullet(
                    bullets,
                    playerCenter - leftPoint + i * (2 * bulletProps.bulletRadius + gap),
                    screenHeight - player.ysize - bulletProps.bulletRadius * 3
                    );
        }
    }
}

void updateBullets () {
    if(player_isAlive) {
        for(Bullet *cursor = bullets; cursor != NULL; cursor = cursor->next) {
            cursor->ypos -= bulletProps.bulletSpeed;
        }
    }
}

void renderBullets () {
    for (Bullet *cursor = bullets; cursor != NULL; cursor = cursor->next) {
        if (cursor->ypos >= bulletProps.bulletRadius && cursor->visible == true) {
            switch (background) {
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