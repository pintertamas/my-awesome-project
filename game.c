#include "global.h"
#include "game.h"
#include "ship.h"
#include "menu.h"
#include "textures.h"

void setupBackupArray () {                                                                                              //stores the necessary data for the game resume
    endGame = (double **) malloc(ballNumber * sizeof(double *));
    for(int i = 0; i < ballNumber; i++) {
        endGame[i] = (double *) malloc(6 * sizeof(double));
    }
}

void stopGame (StopGame stopTheGame) {
    Ball *cursor;
    int i;
    switch (stopTheGame) {
        case PAUSE:
            i = 0;
            for(cursor = balls; cursor != NULL; cursor = cursor->next) {
                endGame[i][0] = cursor->vx;
                endGame[i][1] = cursor->vy;
                endGame[i][2] = cursor->gravity;
                endGame[i][3] = (double)ship.speed;
                endGame[i][4] = (double)bulletSpeed;
                endGame[i][5] = (double)bulletDamage;
                i++;
            }

            i = 0;
            for(cursor = balls; cursor != NULL; cursor = cursor->next) {
                cursor->vx = 0;
                cursor->vy = 0;
                cursor->gravity = 0;
                ship.speed = 0;
                bulletSpeed = 0;
                bulletDamage = 0;
                i++;
            }
            break;
        case RESUME:
            i = 0;
            for(cursor = balls; cursor != NULL; cursor = cursor->next) {
                cursor->vx = endGame[i][0];
                cursor->vy = endGame[i][1];
                cursor->gravity = endGame[i][2];
                ship.speed = endGame[i][3];
                bulletSpeed = endGame[i][4];
                bulletDamage = endGame[i][5];
                i++;
            }
            break;
        default:
            break;
    }
}

bool ShipBallCollision (Ball *head) {
    Ball *cursor;
    for (cursor = head; cursor != NULL; cursor = cursor->next) {
        double d = cursor->ypos + cursor->radius;
        if (screenHeight - ship.ysize < d) {
            if (cursor->xpos + cursor->radius > ship.xpos &&
                    cursor->xpos - cursor->radius < ship.xpos + ship.xsize) {
                return true;
            }
        }
    }
    return false;
}

void shipLife () {
    if (ShipBallCollision(balls) && !inCollision) {
        lifePoints--;
        inCollision = true;
    }
    if (!ShipBallCollision(balls) && inCollision) {
        inCollision = false;
    }
    if (lifePoints == 0) {
        stopGame(PAUSE);
        Vector2 gameOverPosition = {210, 470};
        if (background == SPACE || background == MOUNTAINS) {
            DrawText("GAME OVER!", 150, 400, 50, WHITE);
            DrawTextEx(font, "press X to continue", gameOverPosition, 20, 2, WHITE);
        }
        else {
            DrawText("GAME OVER!", 150, 400, 50, BLACK);
            DrawTextEx(font, "press X to continue", gameOverPosition, 20, 2, BLACK);
        }

        if(IsKeyDown(KEY_X))
            gameState = END;
    }
}

void pause_resume () {
    if (IsKeyPressed(KEY_Z) && !isPaused && lifePoints > 0) {
        stopGame(PAUSE);
        isPaused = true;
    }

    if (IsKeyPressed(KEY_X) && isPaused) {
        stopGame(RESUME);
        isPaused = false;
    }

    if (isPaused) {
        if (background == SPACE || background == MOUNTAINS)
            DrawText("PAUSED!", 170, 400, 60, WHITE);
        else
            DrawText("PAUSED!", 170, 400, 60, BLACK);
    }
}

void BulletBallCollision (Ball *ball_head, Bullet *bullet_head) {
    Bullet *bullet_cursor;
    Ball *ball_cursor;
    for(bullet_cursor = bullet_head; bullet_cursor != NULL; bullet_cursor = bullet_cursor->next) {
        for(ball_cursor = ball_head; ball_cursor != NULL; ball_cursor = ball_cursor->next) {
            int a_square = pow(abs((int)bullet_cursor->xpos - (int)ball_cursor->xpos), 2);
            int b_square = pow(abs((int)bullet_cursor->ypos - (int)ball_cursor->ypos), 2);
            if (sqrt(a_square + b_square) < bulletRadius + ball_cursor->radius) {
                ball_cursor->HP -= bulletDamage;
                bullet_cursor->visible = false;
            }
            if (ball_cursor->HP == 0)
                ball_cursor->visible = false;
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
    Vector2 pausePosition = {150, 30};

    if (background == SPACE) {
        DrawText(FormatText("%d", lifePoints), 50, 30, 30, WHITE);
        DrawTextEx(font, "press Y to pause and X to resume", pausePosition, 20, 2, WHITE);
    } else {
        DrawText(FormatText("%d", lifePoints), 50, 30, 30, BLACK);
        DrawTextEx(font, "press Y to pause and X to resume", pausePosition, 20, 2, BLACK);
    }
}

void endOfGame () {
    Color settingsBackground = {0,190,255};
    freeList_bullet();
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

        if (gameState != END)
            break;
        //-----------------------------------------------------
        BeginDrawing();
        EndDrawing();
        //-----------------------------------------------------
    }
}

void game () {
    setupBackupArray();
    spawnBall();
    while (!WindowShouldClose()) {
        DrawFPS(10, 10);

        renderBackground();
        renderBalls();
        moveShip();
        renderShip();
        ShipBallCollision(balls);

        applyPhysics_Balls(balls);
        updateBalls(balls);

        spawnBullets();
        updateBullets();
        BulletBallCollision(balls, bullets);
        renderBullets();

        isBallAlive(balls);
        pause_resume();
        shipLife();
        bullets = freeBullets_outside(bullets);

        if (!IsThereAnyBall(balls))
            gameState = END;

        if (gameState != GAME)
            break;
        ClearBackground(BACKGROUND_COLOR);
        //-----------------------------------------------------
        BeginDrawing();
        EndDrawing();
        //-----------------------------------------------------
    }
}