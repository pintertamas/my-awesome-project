#include "game.h"
#include "global.h"

int main(void)
{
    //---------------------------------------------------------                                        // Initialization
    InitWindow(screenWidth, screenHeight, "My Awesome Game");

    SetTargetFPS(60);

    setupBalls();
    //----------------------------------------------------------                                       // Main game loop
    while (!WindowShouldClose())                                                // Detect window close button or ESC key
    {
        applyPhysics();

        BeginDrawing();

        ClearBackground(LIGHTGRAY);

        DrawFPS(10, 10);

        EndDrawing();
        //-----------------------------------------------------
    }

    //---------------------------------------------------------
    CloseWindow();                                                                    // Close window and OpenGL context
    //----------------------------------------------------------

    return 0;
}