#ifndef MY_AWESOME_PROJECT_BULLET_H
#define MY_AWESOME_PROJECT_BULLET_H

typedef struct Bullet{
    double xpos;
    double ypos;
    Color color;
    bool visible;
    struct Bullet *next;
}Bullet;

extern Bullet *bullets;
extern clock_t shoot;
extern int shootDelay;
extern int bulletCount;                                                                                                 //number of bullets in one row
extern int bulletRadius;                                                                                                //size of the bullets
extern int bulletSpeed;                                                                                                 //the speed of the bullets
extern int bulletDamage;

void freeList_bullet ();
Bullet* freeBullets_outside (Bullet *head);
void spawnBullets ();
void  updateBullets ();
void renderBullets ();

#endif //MY_AWESOME_PROJECT_BULLET_H