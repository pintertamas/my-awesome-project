#include "menu.h"
#include "game.h"
#include "ball.h"
#include "bullet.h"
#include "player.h"
#include "textures.h"
#include "buttons.h"
#include "settings.h"
#include "debugmalloc.h"

void renderMenu (Color BACKGROUND_COLOR) {

    double timePassed = GetTime();
    timePassed /= 2;
    DrawCircle(menu_screenWidth / 2 - 350 * sin(timePassed), menu_screenHeight / 2 + 200 * cos(timePassed), 50, YELLOW);

    if (((sin(timePassed) < 0 && cos(timePassed) > 0) || (sin(timePassed) > 0 && cos(timePassed) > 0)) && BACKGROUND_COLOR.g > 0) {
        BACKGROUND_COLOR.g--;
        BACKGROUND_COLOR.b--;
    } else if (BACKGROUND_COLOR.b < 255) {
        BACKGROUND_COLOR.g++;
        BACKGROUND_COLOR.b++;
    }

    DrawTexture(menuBackground, 0, 0, WHITE);
    DrawTexture(logo, 20, 450, WHITE);
    Vector2 fontVector = {menu_screenWidth - 150,
                          menu_screenHeight - 20};
    DrawTextEx(font, "Pinter Tamas 2019", fontVector, 15, 2, DARKGRAY);
}

bool isOverButton (Button button) {
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();

    if (mouseX >= button.x && mouseX <= button.x + button.w && mouseY >= button.y && mouseY <= button.y + button.h) {
        return true;
    } else
        return false;
}

void menuButtonClick () {
    if ((isOverButton(startButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) || IsKeyPressed(KEY_ENTER)) {
        DrawTexture(startButton_clicked, startButton.x, startButton.y, WHITE);
        startTime = clock();
        setupPlayer();
    }
    if (isOverButton(settingsButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(settingsButton_clicked, settingsButton.x, settingsButton.y, WHITE);

        startTime = 0;
        gameState = SETTINGS;
    }
    if (isOverButton(scoresButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(scoresButton_clicked, scoresButton.x, scoresButton.y, WHITE);

        gameState = SCORES;
    }
}

void wait_sec (int timeDiff, int time) {
    if (startTime != 0 && gameDifficulty != DIFFICULTY_UNSET && background != BACKGROUND_UNSET) {
        for(int i = 0; i < time; i++) {
            if(timeDiff >= i * 1000 && timeDiff < (i+1) * 1000)
                DrawText(FormatText("%d", time-i), menu_screenWidth / 2 - 15, menu_screenHeight / 3, 60, BLACK);
            if (timeDiff >= time * 1000) {
                startTime = 0;
                gameState = GAME;
            }
        }
    }
}

void renderButtons () {
    DrawTexture(startButton_simple, startButton.x, startButton.y, WHITE);
    DrawTexture(scoresButton_simple, scoresButton.x, scoresButton.y, WHITE);
    DrawTexture(settingsButton_simple, settingsButton.x, settingsButton.y, WHITE);

    int timeDiff = clock() - startTime;
    wait_sec(timeDiff, 3);
    if (startTime != 0) {                                                                                               //without this, the error massages would appear at every start
        if (gameDifficulty == DIFFICULTY_UNSET) {
            if (timeDiff <= 1000)
                DrawText("SELECT DIFFICULTY FIRST!", menu_screenWidth / 2 - 75, scoresButton.y + buttonHeight + 20, 10, BLACK);
        }
        if (background == BACKGROUND_UNSET)
            if (timeDiff <= 1000)
                DrawText("SELECT BACKGROUND FIRST!", menu_screenWidth / 2 - 75, scoresButton.y + buttonHeight + 60, 10, BLACK);
    }
}

void menu () {
    Color BACKGROUND_COLOR = {0,210,255};
    while (!WindowShouldClose()) {

        ClearBackground(BACKGROUND_COLOR);

        renderMenu(BACKGROUND_COLOR);
        renderButtons();
        menuButtonClick();

        if (gameState != MENU)
            break;
        //-----------------------------------------------------
        BeginDrawing();
        EndDrawing();
        //-----------------------------------------------------
    }
}