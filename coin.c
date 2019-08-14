#include "global.h"
#include "ball.h"

void applyPhysics_Coins(Ball *ball) {
    for(int i=0; i<ballNumber; i++) {
        ballbounce(&ball[i], true);
        collisionWall(&ball[i]);
    }
}