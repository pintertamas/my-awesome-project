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
    //----------------------------------------------------------                                                        // Main game loop
    while (!WindowShouldClose())                                                                                        // Detect window close button or ESC key
    {
        renderShip();
        renderBullets(bullets);

        moveShip();
        applyPhysics_Balls(Balls);
        ShipBallCollision();
        updateBalls();

        spawnBullets(bullets);
        updateBullets(bullets);
        //freeBullets();
        //BulletBallCollision();
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
    //freeBullets();
    CloseWindow();                                                                                                      // Close window and OpenGL context
    //---------------------------------------------------------

    return 0;
}