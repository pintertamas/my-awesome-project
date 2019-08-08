//
// Created by Tomi on 30/01/2019.
//
#include "global.h"
#include "textures.h"
#include "game.h"
#include <raylib.h>

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "headball");
    initBall();
    loadImage();
    SetTargetFPS(60);       // Set target frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        HideCursor();
        //collision_wall(&ball);
        updateBall();
        moveBall(&ball);
        //faszkivan(&ball);
        spawnBall();
        //testFly(&ball);
        testBall();
        renderMap();
        showFPS();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        //DrawCircle(ball.x, ball.y, radius, MAROON);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}