#include "game.h"
#include "global.h"
#include "textures.h"

int main(void)
{
    //---------------------------------------------------------                                                         // Initialization
    InitWindow(screenWidth, screenHeight, "My Awesome Game");

    SetTargetFPS(60);

    loadImage();
    setupBalls();
    setupShip();
    setupBullets();
    //----------------------------------------------------------                                                        // Main game loop
    while (!WindowShouldClose())                                                                                        // Detect window close button or ESC key
    {
        renderMap();
        applyPhysics_Balls(Balls);
        moveShip();
        ShipBallCollision();

        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        DrawFPS(10, 10);
        EndDrawing();
        //-----------------------------------------------------
    }

    //---------------------------------------------------------
    freeBalls();
    CloseWindow();                                                                    // Close window and OpenGL context
    //----------------------------------------------------------

    return 0;
}