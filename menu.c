#include "menu.h"
#include "ball.h"
#include "ship.h"
#include "textures.h"
#include "buttons.h"

void renderMenu () {

    double timePassed = GetTime();
    timePassed /= 2;
    DrawCircle(menu_screenWidth / 2 - 350 * sin(timePassed), menu_screenHeight / 2 + 200 * cos(timePassed), 50, YELLOW);

    if(((sin(timePassed) < 0 && cos(timePassed) > 0) || (sin(timePassed) > 0 && cos(timePassed) > 0)) && BACKGROUND_COLOR.g > 0) {
        BACKGROUND_COLOR.g--;
        BACKGROUND_COLOR.b--;
    } else if(BACKGROUND_COLOR.b < 255) {
        BACKGROUND_COLOR.g++;
        BACKGROUND_COLOR.b++;
    }

    DrawTexture(menuBackground, 0, 0, WHITE);
    Vector2 fontVector;
    fontVector.x = menu_screenWidth - 150;
    fontVector.y = menu_screenHeight - 20;
    DrawTextEx(font, "Pinter Tamas 2019", fontVector, 15, 2, DARKGRAY);
}

bool isOverButton (Button button) {
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();

    if(mouseX >= button.x && mouseX <= button.x + button.w && mouseY >= button.y && mouseY <= button.y + button.h) {
        return true;
    } else
        return false;
}

void menuButtonClick () {
    if((isOverButton(startButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) || IsKeyPressed(KEY_ENTER)) {
        DrawTexture(startButton_clicked, startButton.x, startButton.y, WHITE);
        startTime = clock();
        setupBalls();
        setupShip();

    }
    if(isOverButton(settingsButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(settingsButton_clicked, settingsButton.x, settingsButton.y, WHITE);

        startTime = 0;
        gameState = SETTINGS;
    }
    if(isOverButton(scoresButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(scoresButton_clicked, scoresButton.x, scoresButton.y, WHITE);
    }
}

void renderButtons () {
    DrawTexture(startButton_simple, startButton.x, startButton.y, WHITE);
    DrawTexture(scoresButton_simple, scoresButton.x, scoresButton.y, WHITE);
    DrawTexture(settingsButton_simple, settingsButton.x, settingsButton.y, WHITE);

    int timeDiff = clock() - startTime;
    if(startTime != 0 && gameDifficulty != DIFFICULTY_UNSET && background != BACKGROUND_UNSET) {
        if(timeDiff >= 0 && timeDiff < 1000)
            DrawText("3", menu_screenWidth / 2 - 15, menu_screenHeight / 3, 60, BLACK);
        else if(timeDiff >= 1000 && timeDiff < 2000)
            DrawText("2", menu_screenWidth / 2 - 15, menu_screenHeight / 3, 60, BLACK);
        else if(timeDiff >= 2000 && timeDiff < 3000)
            DrawText("1", menu_screenWidth / 2 - 15, menu_screenHeight / 3, 60, BLACK);
        else if(timeDiff >= 3000 && timeDiff < 4000)
            DrawText("LET'S GO", menu_screenWidth / 2 - 150, menu_screenHeight / 3, 60, BLACK);
        else {
            startTime = 0;
            roundStartTime = clock();
            gameState = GAME;
        }
    }
    if(startTime != 0) {
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

    while (!WindowShouldClose()) {

        ClearBackground(BACKGROUND_COLOR);

        //DrawLine(menu_screenWidth/2, 0, menu_screenWidth/2, menu_screenHeight, PINK);

        renderMenu();
        renderButtons();
        menuButtonClick();

        if(gameState != MENU)
            break;
        //-----------------------------------------------------
        BeginDrawing();
        EndDrawing();
        //-----------------------------------------------------
    }
}