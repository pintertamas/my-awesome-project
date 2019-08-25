#ifndef MY_AWESOME_PROJECT_MENU_H
#define MY_AWESOME_PROJECT_MENU_H

#include "global.h"

void menu ();
void renderMenu ();
void loadMenuImages ();
Font font;
clock_t startTime;
clock_t roundStartTime;
bool isOverButton ();
int startButtonX;
int startButtonY;
int settingsButtonX;
int settingsButtonY;
int scoresButtonX;
int scoresButtonY;

#endif //MY_AWESOME_PROJECT_MENU_H