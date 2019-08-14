#include "game.h"
#include "textures.h"
#include "global.h"

int main(void)
{
    //---------------------------------------------------------                                                         // Initialization
    InitWindow(screenWidth, screenHeight, "My Awesome Game");

    SetTargetFPS(60);

    loadImage();
    setupBalls();
    setupShip();
    setupBullet();
    //----------------------------------------------------------                                                        // Main game loop
    while (!WindowShouldClose())                                                                                        // Detect window close button or ESC key
    {
        renderShip();

        moveShip();
        applyPhysics_Balls(Balls);
        ShipBallCollision();

        bulletTest();
        spawnBullet();
        updateBullet();
        renderBullet();
        freeBullets();
        BulletBallCollision();
        isBallAlive();

        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        DrawFPS(10, 10);
        EndDrawing();
        //-----------------------------------------------------
    }

    //---------------------------------------------------------
    freeBalls();
    //freeBullets();
    CloseWindow();                                                                                                      // Close window and OpenGL context
    //----------------------------------------------------------

    return 0;
}