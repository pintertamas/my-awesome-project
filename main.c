#include "global.h"
#include "game.h"
#include "ship.h"
#include "ball.h"
#include "bullet.h"
#include "coin.h"
#include "menu.h"
#include "settings.h"

int main(void)
{
    //----------------------------------------------------------                                                        // Initialization
    InitWindow(menu_screenWidth, menu_screenHeight, "My Awesome Game");
    Image icon = LoadImage("Textures/spaceShip.png");
    SetWindowIcon(icon);
    SetTargetFPS(60);

    loadImage();
    //loadMenuImages();
    font = LoadFont("Textures/font.ttf");
    setupBalls();
    setupShip();
    shoot = clock();
    gameState = MENU;
    gameDifficulty = DIFFICULTY_UNSET;
    background = BACKGROUND_UNSET;
    Color settingsBackground = {0,190,255};
    //----------------------------------------------------------                                                        // Main game loop
    while (!WindowShouldClose())                                                                                        // Detect window close button or ESC key
    {
        switch(gameState) {
            case MENU:
                EnableCursor();
                SetWindowSize(menu_screenWidth, menu_screenHeight);
                SetWindowPosition(resolutionX / 2 - menu_screenWidth / 2, (resolutionY - menu_screenHeight) / 2);
                menu();
                ClearBackground(BACKGROUND_COLOR);
                break;
            case GAME:
                DisableCursor();
                SetWindowSize(screenWidth, screenHeight);
                SetWindowPosition(resolutionX / 2 - screenWidth / 2, (resolutionY - screenHeight) / 2);
                game();
                ClearBackground(BACKGROUND_COLOR);
                DrawFPS(10, 10);
                break;
            case SETTINGS:
                EnableCursor();
                SetWindowSize(menu_screenWidth, menu_screenHeight);
                SetWindowPosition(resolutionX / 2 - menu_screenWidth / 2, (resolutionY - menu_screenHeight) / 2);
                ClearBackground(settingsBackground);
                settings();
                break;
            case SCORES:
                EnableCursor();
                SetWindowSize(screenWidth, screenHeight);
                ClearBackground(BACKGROUND_COLOR);
                //scores();
                break;
            case END:
                EnableCursor();
                SetWindowSize(screenWidth, screenHeight);
                ClearBackground(settingsBackground);
                endOfGame();
                break;
        }
        //-----------------------------------------------------
        BeginDrawing();
        EndDrawing();
        //-----------------------------------------------------
    }
    //---------------------------------------------------------
    //freeBalls();

    //freeList(bullets);
    CloseWindow();                                                                                                      // Close window and OpenGL context
    //---------------------------------------------------------
    return 0;
}