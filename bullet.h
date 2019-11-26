#ifndef MY_AWESOME_PROJECT_BULLET_H
#define MY_AWESOME_PROJECT_BULLET_H

typedef struct Bullet{
    double xpos;
    double ypos;
    bool visible;
    struct Bullet *next;
}Bullet;
extern Bullet *bullets;

typedef struct BulletProperties{
    clock_t shoot;
    int shootDelay;
    int bulletCount;                                                                                                 //number of bullets in one row
    int bulletRadius;                                                                                                //size of the bullets
    int bulletSpeed;                                                                                                 //the speed of the bullets
    int bulletDamage;
}BulletProperties;
BulletProperties bulletProps;

void freeList_bullet ();
Bullet* freeBullets_outside (Bullet *head);
void spawnBullets ();
void  updateBullets ();
void renderBullets ();

#endif //MY_AWESOME_PROJECT_BULLET_H