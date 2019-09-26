#include "global.h"
#include "player.h"
#include "textures.h"
#include "bullet.h"
#include "menu.h"

Bullet *bullets = NULL;
clock_t shoot;
int shootDelay;
int bulletCount;
int bulletRadius;
int bulletSpeed;
int bulletDamage;

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
    int gap = 2;
    double playerCenter = player.xpos + (double)player.xsize / 2;
    double leftPoint = bulletCount * bulletRadius + ((bulletCount - 1) / 2) * gap;

    if (IsKeyDown(KEY_SPACE) && (double)(clock() - shoot) >= shootDelay && player_isAlive) {
        shoot = clock();

        for(int i = 0; i < bulletCount; i++) {
            bullets = list_append_bullet(
                    bullets,
                    playerCenter - leftPoint + i * (2 * bulletRadius + gap),
                    screenHeight - player.ysize - bulletRadius * 3
                    );
        }
    }
}

void updateBullets () {
    if(player_isAlive) {
        for(Bullet *cursor = bullets; cursor != NULL; cursor = cursor->next) {
            cursor->ypos -= bulletSpeed;
        }
    }
}

void renderBullets () {
    for (Bullet *cursor = bullets; cursor != NULL; cursor = cursor->next) {
        if (cursor->ypos >= bulletRadius && cursor->visible == true) {
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