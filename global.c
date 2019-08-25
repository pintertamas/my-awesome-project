#include "global.h"

int resolutionX = 1920;
int resolutionY = 1080;

int screenWidth = 600;
int screenHeight = 900;

int menu_screenWidth = 900;
int menu_screenHeight = 600;

Bullet *bullets = NULL;
clock_t shoot;
int shootDelay = 69;
int shipSpeed = 10;                                                                                                     //the speed of the bullets
int ballNumber = 10;
int ballGravity = 1;
int bulletCount = 5;
int bulletRadius = 5;
int bulletSpeed = 20;