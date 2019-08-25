#include "settings.h"
#include "menu.h"

void settingsButtonClick () {
    if (isOverButton(easyButtonX, easyButtonY, buttonWidth, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if(gameDifficulty == EASY)
            gameDifficulty = UNSET;
        else
        gameDifficulty = EASY;
        printf("easy\n");
    }
    if (isOverButton(mediumButtonX, mediumButtonY, buttonWidth, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if(gameDifficulty == MEDIUM)
            gameDifficulty = UNSET;
        else
        gameDifficulty = MEDIUM;
        printf("medium\n");
    }
    if (isOverButton(hardButtonX, hardButtonY, buttonWidth, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if(gameDifficulty == HARD)
            gameDifficulty = UNSET;
        else
        gameDifficulty = HARD;
        printf("hard\n");
    }
}

void renderSettings () {

    DrawText("SETTINGS", menu_screenWidth / 2 - 200, 10, buttonHeight, LIGHTGRAY);

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
}

void settings () {
    easyButtonX = buttonWidth / 2;
    easyButtonY = buttonHeight + buttonHeight / 2;
    mediumButtonX = menu_screenWidth / 2 - buttonWidth / 2;
    mediumButtonY = buttonHeight + buttonHeight / 2;
    hardButtonX = menu_screenWidth - buttonWidth - buttonWidth / 2;
    hardButtonY = buttonHeight + buttonHeight / 2;

    //DrawLine(menu_screenWidth/2, 0, menu_screenWidth/2, menu_screenHeight, PINK);

    settingsButtonClick();
    renderSettings();
}