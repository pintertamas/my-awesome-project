#include "global.h"
#include "game.h"
#include "player.h"
#include "ball.h"
#include "bullet.h"
#include "menu.h"
#include "settings.h"
#include "textures.h"
#include "buttons.h"
#include "scores.h"
#include "debugmalloc.h"

int main(void)
{
    //----------------------------------------------------------                                                        // Initialization
    InitWindow(menu_screenWidth, menu_screenHeight, "My Awesome Game");
    Image icon = LoadImage("../Textures/heart.png");
    SetWindowIcon(icon);
    SetTargetFPS(60);

    loadImage();
    font = LoadFont("../Textures/font.ttf");
    Color SCORES_COLOR = {0,210,255};
    setupPlayer();
    setupButtons();
    bulletProps.shoot = clock();
    inCollision = false;
    readFromFile(topScores);
    gameState = MENU;
    gameDifficulty = DIFFICULTY_UNSET;
    background = BACKGROUND_UNSET;
    //----------------------------------------------------------
    while (!WindowShouldClose())
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
                SetWindowSize(menu_screenWidth, menu_screenHeight);
                ClearBackground(SCORES_COLOR);
                scores(topScores);
                break;
            case END:
                EnableCursor();
                SetWindowSize(screenWidth, screenHeight);
                endOfGame(topScores);
                break;
        }
    }
    //---------------------------------------------------------
    if(pauseResume != NULL)
        freeBackupArray();
    freeList_bullet();
    freeList_ball();
    writeToFile(topScores);
    CloseWindow();                                                                                                      // Close window and OpenGL context
    //---------------------------------------------------------
    return 0;
}