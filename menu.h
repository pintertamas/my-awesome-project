#ifndef MY_AWESOME_PROJECT_MENU_H
#define MY_AWESOME_PROJECT_MENU_H

#include "global.h"
#include "settings.h"

typedef enum Difficulty {
    DIFFICULTY_UNSET, EASY, MEDIUM, HARD
}Difficulty;

Difficulty gameDifficulty;

typedef enum state {
    MENU, GAME, SETTINGS, SCORES, END
}state;

state gameState;

typedef enum Backgrounds {
    BACKGROUND_UNSET, MOUNTAINS, MOUNTAIN, SPACE, JAPAN
}Backgrounds;

Backgrounds background;

Button startButton;
Button settingsButton;
Button scoresButton;

void menu ();
void renderMenu ();
//void loadMenuImages ();
Font font;
clock_t startTime;
clock_t roundStartTime;
bool isOverButton (Button button);


#endif //MY_AWESOME_PROJECT_MENU_H