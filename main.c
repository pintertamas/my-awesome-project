#include "global.h"
#include "game.h"
#include "player.h"
#include "ball.h"
#include "bullet.h"
#include "menu.h"
#include "settings.h"
#include "textures.h"
#include "buttons.h"

int main(void)
{
    //----------------------------------------------------------                                                        // Initialization
    InitWindow(menu_screenWidth, menu_screenHeight, "My Awesome Game");
    Image icon = LoadImage("Textures/heart.png");
    SetWindowIcon(icon);
    SetTargetFPS(60);

    loadImage();
    font = LoadFont("Textures/font.ttf");
    setupPlayer();
    setupButtons();
    shoot = clock();
    inCollision = false;
    gameState = MENU;
    gameDifficulty = DIFFICULTY_UNSET;
    background = BACKGROUND_UNSET;
    //----------------------------------------------------------                                                        // Main game loop
    while (!WindowShouldClose())                                                                                        // Detect window close button or ESC key
    {
        switch(gameState) {
            case MENU:
                EnableCursor();
                SetWindowSize(menu_screenWidth, menu_screenHeight);
                SetWindowPosition(resolutionX / 2 - menu_screenWidth / 2, (resolutionY - menu_screenHeight) / 2);
                menu();
                break;
            case GAME:
                DisableCursor();
                SetWindowSize(screenWidth, screenHeight);
                SetWindowPosition(resolutionX / 2 - screenWidth / 2, (resolutionY - screenHeight) / 2);
                game();
                break;
            case SETTINGS:
                EnableCursor();
                SetWindowSize(menu_screenWidth, menu_screenHeight);
                SetWindowPosition(resolutionX / 2 - menu_screenWidth / 2, (resolutionY - menu_screenHeight) / 2);
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
                endOfGame();
                break;
        }
    }
    //---------------------------------------------------------
    freeList_bullet();
    freeList_ball();
    CloseWindow();                                                                                                      // Close window and OpenGL context
    //---------------------------------------------------------
    return 0;
}