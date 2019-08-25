#include "settings.h"
#include "menu.h"

void buttonClick () {
    if (isOverButton(startButtonX, startButtonY, buttonWidth, buttonHeight) &&
        IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

    }
}

void renderSettings () {
    if(gameDifficulty == EASY) {

    }

    DrawTexture(easyMode, easyButtunX, easyButtonY, WHITE);
    DrawTexture(mediumMode, startButtonX, startButtonY, WHITE);
    DrawTexture(hardMode, startButtonX, startButtonY, WHITE);

    isOverButton();
}

void settings () {

    renderSettings();
}