#include "settings.h"
#include "menu.h"
#include "textures.h"
#include "ball.h"
#include "bullet.h"
#include "game.h"


Color settingsBackground = {0,190,255};

void settingsButtonClick () {
    if (isOverButton(easyButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (gameDifficulty == EASY)
            gameDifficulty = DIFFICULTY_UNSET;
        else
        gameDifficulty = EASY;
    }
    if (isOverButton(mediumButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (gameDifficulty == MEDIUM)
            gameDifficulty = DIFFICULTY_UNSET;
        else {
            gameDifficulty = MEDIUM;
        }
    }
    if (isOverButton(hardButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (gameDifficulty == HARD)
            gameDifficulty = DIFFICULTY_UNSET;
        else
            gameDifficulty = HARD;
    }
    if (isOverButton(backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(backButton_clicked, backButton.x, backButton.y, WHITE);
        gameState = MENU;
    }

    if (isOverButton(forest) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (background == FOREST)
            background = BACKGROUND_UNSET;
        else
            background = FOREST;
    }
    if (isOverButton(mountains) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (background == MOUNTAINS)
            background = BACKGROUND_UNSET;
        else
            background= MOUNTAINS;
    }
    if (isOverButton(japan) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (background == JAPAN)
            background = BACKGROUND_UNSET;
        else
            background= JAPAN;
    }
    if (isOverButton(space) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (background == SPACE)
            background = BACKGROUND_UNSET;
        else
            background= SPACE;
    }
}

void renderSettings () {

    DrawTexture(settingsLogo, menu_screenWidth / 2 - 440 / 2, 30, WHITE);
    DrawTexture(backButton_simple, backButton.x, backButton.y, WHITE);

    DrawTexture(easyMode, easyButton.x, easyButton.y, WHITE);
    DrawTexture(mediumMode, mediumButton.x, mediumButton.y, WHITE);
    DrawTexture(hardMode, hardButton.x, hardButton.y, WHITE);

    switch (gameDifficulty) {
        case DIFFICULTY_UNSET:
            break;
        case EASY:
            DrawTexture(easyMode_selected, easyButton.x, easyButton.y, WHITE);
            break;
        case MEDIUM:
            DrawTexture(mediumMode_selected, mediumButton.x, mediumButton.y, WHITE);
            break;
        case HARD:
            DrawTexture(hardMode_selected, hardButton.x, hardButton.y, WHITE);
            break;
    }

    DrawTexture(frame_unselected, forest.x - 10, forest.y - 10, WHITE);
    DrawTexture(frame_unselected, mountains.x - 10, mountains.y - 10, WHITE);
    DrawTexture(frame_unselected, japan.x - 10, japan.y - 10, WHITE);
    DrawTexture(frame_unselected, space.x - 10, space.y - 10, WHITE);

    DrawTexture(forest_small, forest.x, forest.y, WHITE);
    DrawTexture(mountains_small, mountains.x, mountains.y, WHITE);
    DrawTexture(japan_small, japan.x, japan.y, WHITE);
    DrawTexture(space_small, space.x, space.y, WHITE);

    switch (background) {
        case BACKGROUND_UNSET:
            break;
        case FOREST:
            DrawTexture(frame_selected, forest.x - 10, forest.y - 10, WHITE);
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

void initGameData () {
    switch (gameDifficulty) {
        case DIFFICULTY_UNSET:
            ballNumber = 0;
            bulletCount = 0;
            lifePoints  = 0;
            break;
        case EASY:
            ballNumber = 4;
            bulletCount = 5;
            lifePoints  = 5;
            break;
        case MEDIUM:
            ballNumber = 5;
            bulletCount = 3;
            lifePoints  = 3;
            break;
        case HARD:
            ballNumber = 6;
            bulletCount = 5;
            lifePoints  = 1;
            break;
    }
}

void settings () {
    while (!WindowShouldClose())                                                                                        // Detect window close button or ESC key
    {
        ClearBackground(settingsBackground);

        initGameData();

        if (IsKeyDown(KEY_BACKSPACE) && gameState != DIFFICULTY_UNSET)
        {
            gameState = MENU;
        }

        //DrawLine(menu_screenWidth/2, 0, menu_screenWidth/2, menu_screenHeight, PINK);

        settingsButtonClick();
        renderSettings();

        if (gameState != SETTINGS)
            break;
        //-----------------------------------------------------
        BeginDrawing();
        EndDrawing();
        //-----------------------------------------------------
    }
}