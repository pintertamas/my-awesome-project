#include "global.h"
#include "ball.h"
#include "textures.h"
#include "player.h"
#include "debugmalloc.h"

Ball *balls = NULL;

void freeList_ball () {
    Ball *tmp;
    while (balls != NULL) {
        tmp = balls;
        balls = balls->next;
        free(tmp);
    }
}

Ball *freeBalls_dead (Ball *head) {
    if(head->HP <= 0) {
        Ball *tmp = head;
        head = head->next;
        free(tmp);
    }
    for(Ball *cursor = head; cursor->next != NULL; cursor = cursor->next) {
        Ball *cursor2 = cursor->next;
        if(cursor2->visible == false) {
           Ball *tmp = cursor2;
           cursor->next = cursor2->next;
           free(tmp);
        }
    }
    return head;
}

Ball *list_append_ball (Ball *head) {
    Ball *new;
    new = (Ball *) malloc(sizeof(Ball));

    int size = GetRandomValue(1, 5);
    switch(size) {
        case 1:
            new->radius = 20;
            new->HP = 64;
            break;
        case 2:
            new->radius = 25;
            new->HP = 128;
            break;
        case 3:
            new->radius = 30;
            new->HP = 256;
            break;
        case 4:
            new->radius = 35;
            new->HP = 512;
            break;
        case 5:
            new->radius = 40;
            new->HP = 1024;
            break;
        default: ;
    }

    int d = GetRandomValue(0,1);
    if(d == 0)
        new->xpos = new->radius;
    else
        new->xpos = screenWidth - new->radius;
    new->ypos = 10;

    new->vx = 0;
    while(new->vx == 0)
        new->vx = (double)GetRandomValue(-5, +5);
    new->vy = (double)GetRandomValue(-10, 0);
    new->ypos = (double)GetRandomValue(new->radius,screenHeight/2);
    new->gravity = 1;
    new->bounce = -1;
    new->visible = true;
    new->next = NULL;

    if(head == NULL) {
        return new;
    }

    Ball *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new;

    return head;
}

void spawnBall () {
    if(ballProps.ballNumber_current < ballProps.ballNumber) {
        balls = list_append_ball(balls);
        ballProps.ballNumber_current ++;
    }
}

void ballBounce(Ball *head, bool gravity) {
    head->vy += head->gravity;
    head->ypos += head->vy/10;
    if (head->ypos > (double)screenHeight - (double)head->radius)
    {
        head->ypos = (double)(screenHeight - head->radius);
        if (gravity == true)
            head->vy *= head->bounce/5;
        else
            head->vy *= head->bounce;
    }

    head->xpos += head->vx;
    //---------------------
    if (gravity == true) {
        head->vx *= (double).996;                                                                                       //slowing the ball down in the x axis
    }
    //---------------------
}

void renderBalls() {
    for (Ball *cursor = balls; cursor != NULL; cursor = cursor->next) {
        if (cursor->visible == true) {
            Vector2 textPosition = {
                    cursor->xpos - cursor->radius / 2,
                    cursor->ypos - cursor->radius / 3};
            switch (cursor->radius) {
                case 20:
                    DrawTexture(greenBall, cursor->xpos - cursor->radius, cursor->ypos - cursor->radius, WHITE);
                    break;
                case 25:
                    DrawTexture(blueBall, cursor->xpos - cursor->radius, cursor->ypos - cursor->radius, WHITE);
                    break;
                case 30:
                    DrawTexture(orangeBall, cursor->xpos - cursor->radius, cursor->ypos - cursor->radius, WHITE);
                    break;
                case 35:
                    DrawTexture(redBall, cursor->xpos - cursor->radius, cursor->ypos - cursor->radius, WHITE);
                    break;
                case 40:
                    DrawTexture(purpleBall, cursor->xpos - cursor->radius, cursor->ypos - cursor->radius, WHITE);
                    break;
                default:
                    break;
            }
            DrawTextEx(font, FormatText("%d", cursor->HP), textPosition, 2 * cursor->radius / 3, 2, BLACK);
        }
    }
}

void collisionWall(Ball *head) {
    if (head->xpos >= (double)(screenWidth - head->radius)) {
        head->xpos = (double)(screenWidth -head->radius); head->vx = -head->vx;
    }
    if (head->xpos <= (double)head->radius) {
        head->xpos = (double)head->radius; head->vx = -head->vx;
    }
    if (head->ypos < (double)head->radius) {
        head->ypos = (double)head->radius; head->vy = -head->vy;
    }
}

void applyPhysics_Balls(Ball *head) {
    if(player_isAlive) {
        for (Ball *cursor = head; cursor != NULL; cursor = cursor->next) {
            if (cursor->visible == true) {
                ballBounce(cursor, false);
                collisionWall(cursor);
            }
        }
    }
}

void updateBalls(Ball *head) {
    for(Ball *cursor = head; cursor != NULL; cursor = cursor->next) {
        if (cursor->HP <= 64) {
            cursor->radius = 20;
        }
        if (cursor->HP > 64 && cursor->HP <= 128) {
            cursor->radius = 25;
        }
        if (cursor->HP > 128 && cursor->HP <= 256) {
            cursor->radius = 30;
        }
        if (cursor->HP > 256 && cursor->HP <= 512) {
            cursor->radius = 35;
        }
        if (cursor->HP > 512 && cursor->HP <= 1024) {
            cursor->radius = 40;
        }
    }
}