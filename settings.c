#include "settings.h"
#include "menu.h"

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
    DrawTexture(japan_small, japanThumbX, japanThumbY, WHITE);
    DrawTexture(space_small, spaceThumbX, spaceThumbY, WHITE);

    switch (background) {
        case BACKGROUND_UNSET:
            break;
        case MOUNTAIN:
            DrawTexture(frame_selected, mountainThumbX - 10, mountainThumbY - 10, WHITE);
            break;
        case MOUNTAINS:
            DrawTexture(frame_selected, mountainsThumbX -10, mountainsThumbY - 10, WHITE);
            break;
        case JAPAN:
            DrawTexture(frame_selected, japanThumbX -10, japanThumbY -10, WHITE);
            break;
        case SPACE:
            DrawTexture(frame_selected, spaceThumbX -10, spaceThumbY - 10, WHITE);
            break;
    }
}

void settings () {

    Color settingsBackground = {0,190,255};
    while (!WindowShouldClose())                                                                                        // Detect window close button or ESC key
    {
        ClearBackground(settingsBackground);

        backButtonX = buttonHeight / 4;
        backButtonY = buttonHeight / 4;

        easyButtonX = buttonWidth / 2;
        easyButtonY = buttonHeight + buttonHeight / 2;
        mediumButtonX = menu_screenWidth / 2 - buttonWidth / 2;
        mediumButtonY = buttonHeight + buttonHeight / 2;
        hardButtonX = menu_screenWidth - buttonWidth - buttonWidth / 2;
        hardButtonY = buttonHeight + buttonHeight / 2;

        thumbnailWidth = 133;
        thumbnailHeight = 200;
        gap = (menu_screenWidth - 4 * thumbnailWidth) / 5;

        mountainThumbX = gap;
        mountainThumbY = menu_screenHeight - thumbnailHeight - 80;
        mountainsThumbX = thumbnailWidth + 2 * gap;
        mountainsThumbY = menu_screenHeight - thumbnailHeight - 80;
        japanThumbX = 2 * thumbnailWidth + 3 * gap;
        japanThumbY = menu_screenHeight - thumbnailHeight - 80;
        spaceThumbX = 3 * thumbnailWidth + 4 * gap;
        spaceThumbY = menu_screenHeight - thumbnailHeight - 80;

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