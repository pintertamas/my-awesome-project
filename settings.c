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
    if (isOverButton(backButtonX, backButtonY, buttonWidth / 2, buttonHeight / 2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(backButton_clicked, backButtonX, backButtonY, WHITE);
        gameState = MENU;
    }
}

void renderSettings () {

    DrawTexture(settingsLogo, menu_screenWidth / 2 - 440 / 2, 30, WHITE);
    DrawTexture(backButton_simple, backButtonX, backButtonY, WHITE);

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

    DrawTexture(frame_unselected, mountainFrameX, mountainFrameY, WHITE);
    DrawTexture(frame_unselected, mountainsFrameX, mountainsFrameY, WHITE);
    DrawTexture(frame_unselected, japanFrameX, japanFrameY, WHITE);
    DrawTexture(frame_unselected, spaceFrameX, spaceFrameY, WHITE);

    /*DrawTexture(frame_unselected, mountainFrameX, mountainFrameY, WHITE);
    DrawTexture(frame_unselected, mountainsFrameX, mountainsFrameY, WHITE);
    DrawTexture(frame_unselected, japanFrameX, japanFrameY, WHITE);
    DrawTexture(frame_unselected, spaceFrameX, spaceFrameY, WHITE);*/

    switch (background) {
        case BACKGROUND_UNSET:
            break;
        case MOUNTAIN:
            DrawTexture(frame_selected, mountainFrameX, mountainFrameY, WHITE);
            break;
        case MOUNTAINS:
            DrawTexture(frame_selected, mountainsFrameX, mountainsFrameY, WHITE);
            break;
        case JAPAN:
            DrawTexture(frame_selected, japanFrameX, japanFrameY, WHITE);
            break;
        case SPACE:
            DrawTexture(frame_selected, spaceFrameX, spaceFrameY, WHITE);
            break;
    }
}

void settings () {

    backButtonX = buttonHeight / 4;
    backButtonY = buttonHeight / 4;

    easyButtonX = buttonWidth / 2;
    easyButtonY = buttonHeight + buttonHeight / 2;
    mediumButtonX = menu_screenWidth / 2 - buttonWidth / 2;
    mediumButtonY = buttonHeight + buttonHeight / 2;
    hardButtonX = menu_screenWidth - buttonWidth - buttonWidth / 2;
    hardButtonY = buttonHeight + buttonHeight / 2;

    thumbnailWidth = 200;
    thumbnailHeight = 133;
    mountainThumbX = ;
    mountainThumbY = ;
    mountainsThumbX = ;
    mountainsThumbY = ;
    japanThumbX = ;
    japanThumbY = ;
    spaceThumbX = ;
    spaceThumbY = ;

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