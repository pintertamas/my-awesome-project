#include "settings.h"
#include "menu.h"

void settingsButtonClick () {
    if (isOverButton(easyButtonX, easyButtonY, buttonWidth, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        gameDifficulty = EASY;
        printf("seggfasz");
    }
    if (isOverButton(mediumButtonX, mediumButtonY, buttonWidth, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        gameDifficulty = EASY;
        printf("seggfasz");
    }
    if (isOverButton(hardButtonX, hardButtonY, buttonWidth, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        gameDifficulty = EASY;
        printf("seggfasz");
    }
}

void renderSettings () {

    switch (gameDifficulty) {
        case UNSET:
            DrawTexture(easyMode, easyButtonX, easyButtonY, WHITE);
            DrawTexture(mediumMode, mediumButtonX, mediumButtonY, WHITE);
            DrawTexture(hardMode, hardButtonX, hardButtonY, WHITE);
            break;
        case EASY:
            DrawTexture(easyMode_selected, easyButtonX, easyButtonY, WHITE);
            DrawTexture(mediumMode, mediumButtonX, mediumButtonY, WHITE);
            DrawTexture(hardMode, hardButtonX, hardButtonY, WHITE);
            break;
        case MEDIUM:
            DrawTexture(easyMode, easyButtonX, easyButtonY, WHITE);
            DrawTexture(mediumMode_selected, mediumButtonX, mediumButtonY, WHITE);
            DrawTexture(hardMode, hardButtonX, hardButtonY, WHITE);
            break;
        case HARD:
            DrawTexture(easyMode, easyButtonX, easyButtonY, WHITE);
            DrawTexture(mediumMode, mediumButtonX, mediumButtonY, WHITE);
            DrawTexture(hardMode_selected, hardButtonX, hardButtonY, WHITE);
            break;
    }


    isOverButton();
}

void settings () {
    easyButtonX = buttonWidth / 2;
    easyButtonY = buttonHeight + buttonHeight / 2;
    mediumButtonX = menu_screenWidth / 2 - buttonWidth / 2;
    mediumButtonY = buttonHeight + buttonHeight / 2;
    hardButtonX = menu_screenWidth - buttonWidth / 2;
    hardButtonY = buttonHeight + buttonHeight / 2;


    renderSettings();
}