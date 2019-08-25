#include "settings.h"
#include "menu.h"

void settingsButtonClick () {
    if (isOverButton(easyButtonX, easyButtonY, buttonWidth, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if(gameDifficulty == EASY)
            gameDifficulty = DIFFICULTY_UNSET;
        else
        gameDifficulty = EASY;
    }
    if (isOverButton(mediumButtonX, mediumButtonY, buttonWidth, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if(gameDifficulty == MEDIUM)
            gameDifficulty = DIFFICULTY_UNSET;
        else {
            gameDifficulty = MEDIUM;
        }

    }
    if (isOverButton(hardButtonX, hardButtonY, buttonWidth, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if(gameDifficulty == HARD)
            gameDifficulty = DIFFICULTY_UNSET;
        else
        gameDifficulty = HARD;
    }
}

void renderSettings () {

    DrawText("SETTINGS", menu_screenWidth / 2 - 200, 10, buttonHeight, LIGHTGRAY);
    DrawTexture(backButton_simple, );

    switch (gameDifficulty) {
        case DIFFICULTY_UNSET:
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

    backButtonX = buttonHeight / 4;
    backButtonY =buttonHeight / 4;
    easyButtonX = buttonWidth / 2;
    easyButtonY = buttonHeight + buttonHeight / 2;
    mediumButtonX = menu_screenWidth / 2 - buttonWidth / 2;
    mediumButtonY = buttonHeight + buttonHeight / 2;
    hardButtonX = menu_screenWidth - buttonWidth - buttonWidth / 2;
    hardButtonY = buttonHeight + buttonHeight / 2;

    switch (gameDifficulty) {
        case DIFFICULTY_UNSET:
            break;
        case EASY:
            ballNumber = 3;
            bulletCount = 1;
            break;
        case MEDIUM:
            ballNumber = 5;
            bulletCount = 3;
            break;
        case HARD:
            ballNumber = 8;
            bulletCount = 5;
            break;
    }

    if(IsKeyDown(KEY_BACKSPACE) && gameState != DIFFICULTY_UNSET)
        gameState = MENU;



    //DrawLine(menu_screenWidth/2, 0, menu_screenWidth/2, menu_screenHeight, PINK);

    settingsButtonClick();
    renderSettings();
}