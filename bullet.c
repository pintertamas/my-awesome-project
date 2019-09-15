#include "global.h"
#include "player.h"
#include "textures.h"
#include "bullet.h"
#include "game.h"
#include "menu.h"

Bullet *bullets = NULL;
clock_t shoot;
int shootDelay = 69;
int bulletCount = 5;
int bulletRadius = 5;
int bulletSpeed = 15;
int bulletDamage = 1;

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
    double playerCenter = player.xpos + (double)player.xsize / 2;
    double leftPoint = (bulletCount - 0.5) * 2 * bulletRadius;


    if (IsKeyDown(KEY_SPACE) && (double)(clock() - shoot) >= shootDelay && lifePoints != 0) {
        //printf("%f\n", (double)(clock() - shoot));
        shoot = clock();

        for(int i = 0; i < bulletCount; i++) {
            bullets = list_append_bullet(
                    bullets,
                    playerCenter - leftPoint + i * 4 * bulletRadius + bulletRadius,
                    screenHeight - player.ysize - bulletRadius * 3
                    );
            //printf("%d ", (int)bullets->xpos);
        }
    }
}

void updateBullets () {
    for(Bullet *cursor = bullets; cursor != NULL; cursor = cursor->next) {
        cursor->ypos -= bulletSpeed;
    }
}

void renderBullets () {
    for(Bullet *cursor = bullets; cursor != NULL; cursor = cursor->next) {
        if (cursor->ypos >= bulletRadius && cursor->visible == true) {
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