#ifndef MY_AWESOME_PROJECT_BUTTONS_H
#define MY_AWESOME_PROJECT_BUTTONS_H

typedef struct Button{
    int x;
    int y;
    int w;
    int h;
}Button;

int buttonWidth;
int buttonHeight;

Button startButton;
Button settingsButton;
Button scoresButton;
Button easyButton;
Button mediumButton;
Button hardButton;
Button backButton;
Button mountain;
Button mountains;
Button japan;
Button space;

void setupButtons();

#endif //MY_AWESOME_PROJECT_BUTTONS_H
