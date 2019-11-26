#include "global.h"
#include "game.h"
#include "player.h"
#include "menu.h"
#include "textures.h"
#include "settings.h"
#include "debugmalloc.h"

Vector2 position = { 10.0f, 30.0f };
Rectangle frameRec = { 0.0f, 0.0f, 140 / 4, 30 };
int currentFrame = 0;
int framesCounter = 0;
int framesSpeed = 8;
Pause *pauseResume = NULL;

void setupBackupArray () {                                                                                              //stores the necessary data for the game resume
    pauseResume = (Pause *) malloc(ballProps.ballNumber * sizeof(Pause));
}

void freeBackupArray () {
    free(pauseResume);
    pauseResume = NULL;
}

void stopGame (StopGame stopTheGame) {
    Ball *cursor;
    int i;
    switch (stopTheGame) {
        case PAUSE:
            isPaused = true;
            i = 0;
            for(cursor = balls; cursor != NULL; cursor = cursor->next) {
                pauseResume[i].vx = cursor->vx;
                pauseResume[i].vy = cursor->vy;
                pauseResume[i].gravity = cursor->gravity;
                pauseResume[i].playerSpeed = player.speed;
                pauseResume[i].bulletSpeed = bulletProps.bulletSpeed;
                pauseResume[i].bulletDamage = bulletProps.bulletDamage;
                i++;
            }

            i = 0;
            for(cursor = balls; cursor != NULL; cursor = cursor->next) {
                cursor->vx = 0;
                cursor->vy = 0;
                cursor->gravity = 0;
                player.speed = 0;
                bulletProps.bulletSpeed = 0;
                bulletProps.bulletDamage = 0;
                i++;
            }
            break;
        case RESUME:
            isPaused = false;
            i = 0;
            for(cursor = balls; cursor != NULL; cursor = cursor->next) {
                cursor->vx = pauseResume[i].vx;
                cursor->vy = pauseResume[i].vy;
                cursor->gravity = pauseResume[i].gravity;
                player.speed = pauseResume[i].playerSpeed;
                bulletProps.bulletSpeed = pauseResume[i].bulletSpeed;
                bulletProps.bulletDamage = pauseResume[i].bulletDamage;
                i++;
            }
            break;
        default:
            break;
    }
}

bool playerBallCollision (Ball *head) {
    if(player_isAlive) {
        Ball *cursor;
        for (cursor = head; cursor != NULL; cursor = cursor->next) {
            double d = cursor->ypos + cursor->radius;
            if (screenHeight - player.ysize < d) {
                if (cursor->xpos + cursor->radius > player.xpos &&
                    cursor->xpos - cursor->radius < player.xpos + player.xsize) {
                    return true;
                }
            }
        }
    }
    return false;
}

void playerLife () {
    if (playerBallCollision(balls) && !inCollision) {
        DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
        lifePoints--;
        damageTime = clock();
        inCollision = true;
    }
    if (!playerBallCollision(balls) && inCollision) {
        inCollision = false;
    }
    if (lifePoints <= 0) {
        player_isAlive = false;
    }

    if(player_isAlive == false) {
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
        setupBackupArray();
        stopGame(PAUSE);
        isPaused = true;
    }

    if (IsKeyPressed(KEY_X) && isPaused) {
        stopGame(RESUME);
        freeBackupArray();
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
            if (sqrt(a_square + b_square) < bulletProps.bulletRadius + ball_cursor->radius) {
                if(bullet_cursor->visible == true){
                    ball_cursor->HP -= bulletProps.bulletDamage;
                    ballProps.damageDealt += bulletProps.bulletDamage;
                    bullet_cursor->visible = false;
                }
            }
            if (ball_cursor->HP <= 0) {
                if(ball_cursor->visible == true) {
                    ballProps.ballNumber_current --;
                    ballProps.balls_destroyed++;
                }
                ball_cursor->visible = false;
            }
        }
    }
}

void onDamageAnimation_heart () {
    if(player_isAlive) {
        framesCounter++;

        if (framesCounter >= (60 / framesSpeed)) {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;

            frameRec.x = (float) currentFrame * 140 / 4;
        }
        DrawTextureRec(heart_onDamage, frameRec, position, WHITE);  // Draw part of the texture
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

    if(clock() - damageTime <= 500) {
        onDamageAnimation_heart();
    } else {
        DrawTexture(heart, 10, 30, WHITE);
    }
    Vector2 pausePosition = {150, 30};

    if (background == SPACE) {
        DrawText(FormatText("%d", lifePoints), 50, 30, 30, WHITE);
        DrawTextEx(font, "press Y to pause and X to resume", pausePosition, 20, 2, WHITE);
    } else {
        DrawText(FormatText("%d", lifePoints), 50, 30, 30, BLACK);
        DrawTextEx(font, "press Y to pause and X to resume", pausePosition, 20, 2, BLACK);
    }
}

void game () {
    player_isAlive = true;
    setupPlayer();
    roundStart = clock();
    damageTime = 0;
    ballProps.ballNumber_current = 0;
    ballProps.ballNumber_current = 0;
    ballProps.balls_destroyed = 0;
    ballProps.damageDealt = 0;
    initGameData();
    while (!WindowShouldClose()) {
        renderBackground();
        renderBalls();
        movePlayer();
        renderPlayer();
        playerBallCollision(balls);
        BulletBallCollision(balls, bullets);

        applyPhysics_Balls(balls);
        updateBalls(balls);
        spawnBall();

        spawnBullets();
        updateBullets();
        renderBullets();
        bullets = freeBullets_outside(bullets);
        balls = freeBalls_dead(balls);

        pause_resume();
        playerLife();

        if (gameState != GAME) {
            freeList_bullet();
            freeList_ball();
            roundEnd = clock();
            break;
        }
        ClearBackground(BACKGROUND_COLOR);
        //-----------------------------------------------------
        BeginDrawing();
        EndDrawing();
        //-----------------------------------------------------
    }
}