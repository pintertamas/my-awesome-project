#include "global.h"
#include "game.h"
#include "ship.h"
#include "ball.h"
#include "bullet.h"
#include "coin.h"

int main(void)
{
    //----------------------------------------------------------                                                        // Initialization
    InitWindow(screenWidth, screenHeight, "My Awesome Game");

    SetTargetFPS(60);

    loadImage();
    setupBalls();
    setupShip();
    shoot = clock();
    //----------------------------------------------------------                                                        // Main game loop
    while (!WindowShouldClose())                                                                                        // Detect window close button or ESC key
    {
        renderShip();
        moveShip();
        ShipBallCollision();

        applyPhysics_Balls(Balls);
        updateBalls();

        spawnBullets();
        updateBullets();
        BulletBallCollision();
        renderBullets();

        isBallAlive();

        //-----------------------------------------------------
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        DrawFPS(10, 10);
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