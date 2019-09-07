#include "global.h"
#include "game.h"
#include "ball.h"
#include "bullet.h"
#include "ship.h"
#include "menu.h"
#include "textures.h"

void stopGame (StopGame stopTheGame) {
    int endGame[ballNumber][6];
    switch (stopTheGame) {
        case PAUSE:
            for(int i = 0; i < ballNumber; i++) {
                endGame[i][0] = Balls[i].vx;
                endGame[i][1] = Balls[i].vy;
                endGame[i][2] = Balls[i].gravity;
                endGame[i][3] = ship.speed;
                endGame[i][4] = bulletSpeed;
                endGame[i][5] = bulletDamage;
            }

            for(int i = 0; i < ballNumber; i++) {
                Balls[i].vx = 0;
                Balls[i].vy = 0;
                Balls[i].gravity = 0;
                ship.speed = 0;
                bulletSpeed = 0;
                bulletDamage = 0;
            }
            break;
        case RESUME:
            for(int i = 0; i < ballNumber; i++) {
                Balls[i].vx = endGame[i][0];
                Balls[i].vy = endGame[i][1];
                Balls[i].gravity = endGame[i][2];
                ship.speed = endGame[i][3];
                bulletSpeed = endGame[i][4];
                bulletDamage = endGame[i][5];
            }
            break;
        default:
            break;
    }
}

bool ShipBallCollision () {
    for (int i = 0; i < ballNumber; i++) {
        double d = Balls[i].ypos + Balls[i].radius;
        if (screenHeight - ship.ysize < d) {
            if (Balls[i].xpos + Balls[i].radius > ship.xpos &&
                Balls[i].xpos - Balls[i].radius < ship.xpos + ship.xsize) {
                //Balls[i].color = BLACK;
                return true;
            }
        }
    }
    return false;
}

void shipLife () {
    if(ShipBallCollision() && !inCollision) {
        lifePoints--;
        inCollision = true;
    }
    if(!ShipBallCollision() && inCollision) {
        inCollision = false;
    }
    if(lifePoints == 0)
        stopGame(PAUSE);
    //stopGame(RESUME);
}

void BulletBallCollision () {
    Bullet *cursor;
    for(cursor = bullets; cursor != NULL; cursor = cursor->next) {
        for(int i = 0; i < ballNumber; i++) {
            int a_square = pow(abs((int)cursor->xpos - (int)Balls[i].xpos), 2);
            int b_square = pow(abs((int)cursor->ypos - (int)Balls[i].ypos), 2);
            if (sqrt(a_square + b_square) < bulletRadius + Balls[i].radius) {
                Balls[i].HP -= bulletDamage;
            }
            if(Balls[i].HP == 0)
                Balls[i].visible = 0;
        }
    }
}

void renderBackground () {
    switch (background) {
        case BACKGROUND_UNSET:
            DrawTexture(background_unknown, 0, 0, WHITE);
            break;
        case FOREST:
            DrawTexture(background_forest, 0, 0, WHITE);
            break;
        case MOUNTAINS:
            DrawTexture(background_mountains, 0, 0, WHITE);
            break;
        case JAPAN:
            DrawTexture(background_japan, 0, 0, WHITE);
            break;
        case SPACE:
            DrawTexture(background_space, 0, 0, WHITE);
            break;
    }

    DrawTexture(heart, 10, 30, WHITE);

    if(background == SPACE)
        DrawText(FormatText("%d", lifePoints), 50, 30, 30, WHITE);
    else
        DrawText(FormatText("%d", lifePoints), 50, 30, 30, BLACK);
}

void endOfGame () {
    Color settingsBackground = {0,190,255};
    while (!WindowShouldClose()) {
        DrawTexture(background_gameOver, 0, 0, WHITE);
        DrawTexture(backButton_simple, backButton.x, backButton.y, WHITE);
        Vector2 scorePosition = {140,330};
        DrawTextEx(font, "We don't keep score, so everyone wins.", scorePosition, 20, 2, BLACK);

        if (isOverButton(backButton) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            DrawTexture(backButton_clicked, backButton.x, backButton.y, WHITE);
            startTime = 0;
            gameState = MENU;
        }
        ClearBackground(settingsBackground);

        if(gameState != END)
            break;
        //-----------------------------------------------------
        BeginDrawing();
        EndDrawing();
        //-----------------------------------------------------
    }
}

void game () {
    while (!WindowShouldClose()) {
        DrawFPS(10, 10);

        renderBackground();
        renderShip();
        moveShip();
        ShipBallCollision();
        shipLife();

        applyPhysics_Balls(Balls);
        updateBalls();

        spawnBullets();
        updateBullets();
        BulletBallCollision();
        renderBullets();

        isBallAlive();

        if (!IsThereAnyBall())
            gameState = END;

        if(gameState != GAME)
            break;
        ClearBackground(BACKGROUND_COLOR);
        //-----------------------------------------------------
        BeginDrawing();
        EndDrawing();
        //-----------------------------------------------------
    }
}