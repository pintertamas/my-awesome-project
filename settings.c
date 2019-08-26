#include "settings.h"
#include "menu.h"
#include "textures.h"
#include "ball.h"
#include "bullet.h"

void settingsButtonClick () {
    if (isOverButton(easyButtonX, easyButtonY, buttonWidth, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (gameDifficulty == EASY)
            gameDifficulty = DIFFICULTY_UNSET;
        else
        gameDifficulty = EASY;
    }
    if (isOverButton(mediumButtonX, mediumButtonY, buttonWidth, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (gameDifficulty == MEDIUM)
            gameDifficulty = DIFFICULTY_UNSET;
        else {
            gameDifficulty = MEDIUM;
        }
    }
    if (isOverButton(hardButtonX, hardButtonY, buttonWidth, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (gameDifficulty == HARD)
            gameDifficulty = DIFFICULTY_UNSET;
        else
            gameDifficulty = HARD;
    }
    if (isOverButton(backButtonX, backButtonY, buttonWidth / 2, buttonHeight / 2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(backButton_clicked, backButtonX, backButtonY, WHITE);
        gameState = MENU;
    }

    if (isOverButton(mountainThumbX, mountainThumbY, thumbnailWidth, thumbnailHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (background == MOUNTAIN)
            background = BACKGROUND_UNSET;
        else
            background = MOUNTAIN;
    }
    if (isOverButton(mountainsThumbX, mountainsThumbY, thumbnailWidth, thumbnailHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (background == MOUNTAINS)
            background = BACKGROUND_UNSET;
        else
            background= MOUNTAINS;
    }
    if (isOverButton(japanThumbX, japanThumbY, thumbnailWidth, thumbnailHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (background == JAPAN)
            background = BACKGROUND_UNSET;
        else
            background= JAPAN;
    }
    if (isOverButton(spaceThumbX, spaceThumbY, thumbnailWidth, thumbnailHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (background == SPACE)
            background = BACKGROUND_UNSET;
        else
            background= SPACE;
    }
}

void renderSettings () {

    DrawTexture(settingsLogo, menu_screenWidth / 2 - 440 / 2, 30, WHITE);
    DrawTexture(backButton_simple, backButtonX, backButtonY, WHITE);

    DrawTexture(easyMode, easyButtonX, easyButtonY, WHITE);
    DrawTexture(mediumMode, mediumButtonX, mediumButtonY, WHITE);
    DrawTexture(hardMode, hardButtonX, hardButtonY, WHITE);

    switch (gameDifficulty) {
        case DIFFICULTY_UNSET:
            break;
        case EASY:
            DrawTexture(easyMode_selected, easyButtonX, easyButtonY, WHITE);
            break;
        case MEDIUM:
            DrawTexture(mediumMode_selected, mediumButtonX, mediumButtonY, WHITE);
            break;
        case HARD:
            DrawTexture(hardMode_selected, hardButtonX, hardButtonY, WHITE);
            break;
    }

    DrawTexture(frame_unselected, mountainThumbX - 10, mountainThumbY - 10, WHITE);
    DrawTexture(frame_unselected, mountainsThumbX - 10, mountainsThumbY - 10, WHITE);
    DrawTexture(frame_unselected, japanThumbX - 10, japanThumbY - 10, WHITE);
    DrawTexture(frame_unselected, spaceThumbX - 10, spaceThumbY - 10, WHITE);

    DrawTexture(mountain_small, mountainThumbX, mountainThumbY, WHITE);
    DrawTexture(mountains_small, mountainsThumbX, mountainsThumbY, WHITE);
    DrawTexture(japan_small, japan.x, japan.y, WHITE);
    DrawTexture(space_small, space.x, space.y, WHITE);

    switch (background) {
        case BACKGROUND_UNSET:
            break;
        case MOUNTAIN:
            DrawTexture(frame_selected, mountain.x - 10, mountain.y - 10, WHITE);
            break;
        case MOUNTAINS:
            DrawTexture(frame_selected, mountains.x -10, mountains.y - 10, WHITE);
            break;
        case JAPAN:
            DrawTexture(frame_selected, japan.x -10, japan.y -10, WHITE);
            break;
        case SPACE:
            DrawTexture(frame_selected, space.x -10, space.y - 10, WHITE);
            break;
    }
}

void settings () {

    Color settingsBackground = {0,190,255};
    while (!WindowShouldClose())                                                                                        // Detect window close button or ESC key
    {
        ClearBackground(settingsBackground);

        backButton.x = buttonHeight / 4;
        backButton.y = buttonHeight / 4;

        easyButton.x = buttonWidth / 2;
        easyButton.y = buttonHeight + buttonHeight / 2;
        mediumButton.x = menu_screenWidth / 2 - buttonWidth / 2;
        mediumButton.y = buttonHeight + buttonHeight / 2;
        hardButton.x = menu_screenWidth - buttonWidth - buttonWidth / 2;
        hardButton.y = buttonHeight + buttonHeight / 2;

        int thumbnailWidth = 133;
        int thumbnailHeight = 200;
        int gap = (menu_screenWidth - 4 * thumbnailWidth) / 5;

        mountain.x = gap;
        mountain.y = menu_screenHeight - thumbnailHeight - 80;
        mountains.x = thumbnailWidth + 2 * gap;
        mountains.y = menu_screenHeight - thumbnailHeight - 80;
        japan.x = 2 * thumbnailWidth + 3 * gap;
        japan.y = menu_screenHeight - thumbnailHeight - 80;
        space.x = 3 * thumbnailWidth + 4 * gap;
        space.y = menu_screenHeight - thumbnailHeight - 80;

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

        if (IsKeyDown(KEY_BACKSPACE) && gameState != DIFFICULTY_UNSET)
        {
            gameState = MENU;
        }

        //DrawLine(menu_screenWidth/2, 0, menu_screenWidth/2, menu_screenHeight, PINK);

        settingsButtonClick();
        renderSettings();

        if(gameState != SETTINGS)
            break;
        //-----------------------------------------------------
        BeginDrawing();
        EndDrawing();
        //-----------------------------------------------------
    }
}