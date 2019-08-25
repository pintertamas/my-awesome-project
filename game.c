#include "global.h"
#include "ball.h"
#include "bullet.h"
#include "ship.h"
#include "settings.h"
#include "menu.h"

bool ShipBallCollision (){
    for (int i = 0; i < ballNumber; i++) {
        double d = Balls[i].ypos + Balls[i].radius;
        if (screenHeight - (double)ship.ysize/2 > d && d > (screenHeight - ship.ysize)) {
            if (Balls[i].xpos > ship.xpos - (double) ship.xsize / 4 &&
                Balls[i].xpos < ship.xpos + (double) ship.xsize / 4) {
                //Balls[i].color = BLACK;
                //pauseGame();
                return true;
            }
        }else if((double)screenHeight - (double)ship.ysize/2 < d) {
            if (Balls[i].xpos > ship.xpos - (double) ship.xsize &&
                Balls[i].xpos < ship.xpos + (double) ship.xsize) {
                //Balls[i].color = BLACK;
                //pauseGame();
                return true;
            }
        }
    }
    return false;
}

void BulletBallCollision () {
    Bullet *cursor;
    for(cursor = bullets; cursor != NULL; cursor = cursor->next) {
        for(int i = 0; i < ballNumber; i++) {
            int a_square = pow(abs((int)cursor->xpos - (int)Balls[i].xpos), 2);
            int b_square = pow(abs((int)cursor->ypos - (int)Balls[i].ypos), 2);
            if (sqrt(a_square + b_square) < bulletRadius + Balls[i].radius) {
                Balls[i].HP -= 1;
            }
            if(Balls[i].HP == 0)
                Balls[i].visible = 0;
        }
    }
}

void pauseGame () {
    for(int i = 0; i < ballNumber; i++) {
        Balls[i].vx = 0;
        Balls[i].vy = 0;
        Balls[i].gravity = 0;
        ship.speed = 0;
    }
}

void resumeGame () {
    for(int i = 0; i < ballNumber; i++) {
        Balls[i].vx = 10;
        Balls[i].vy = 10;
        Balls[i].gravity = 1;
        ship.speed = shipSpeed;
    }
}

void loadImage(){
    textures[0] = LoadImage("Textures/spaceShip.png");                                                         // Loaded in CPU memory (RAM)
    ImageFormat(&textures[0], UNCOMPRESSED_R8G8B8A8);                                                        // Format image to RGBA 32bit (required for texture update)
    shipTexture = LoadTextureFromImage(textures[0]);                                                             // Image converted to texture, GPU memory (VRAM)

    textures[1] = LoadImage("Textures/bullet.png");
    ImageFormat(&textures[1], UNCOMPRESSED_R8G8B8A8);
    bulletTexture = LoadTextureFromImage(textures[1]);

    textures[2] = LoadImage("Textures/backgrounds/background_mountains.png");
    ImageFormat(&textures[2], UNCOMPRESSED_R8G8B8A8);
    background_mountain = LoadTextureFromImage(textures[2]);

    textures[21] = LoadImage("Textures/backgrounds/background_mountain.png");
    ImageFormat(&textures[2], UNCOMPRESSED_R8G8B8A8);
    background_mountain = LoadTextureFromImage(textures[2]);

    textures[22] = LoadImage("Textures/backgrounds/background_japan.png");
    ImageFormat(&textures[22], UNCOMPRESSED_R8G8B8A8);
    background_japan = LoadTextureFromImage(textures[22]);

    textures[23] = LoadImage("Textures/backgrounds/background_spacen.png");
    ImageFormat(&textures[23], UNCOMPRESSED_R8G8B8A8);
    background_space = LoadTextureFromImage(textures[23]);

    textures[24] = LoadImage("Textures/thumbnails/frame_selected.png");
    ImageFormat(&textures[24], UNCOMPRESSED_R8G8B8A8);
    frame_selected = LoadTextureFromImage(textures[24]);

    textures[25] = LoadImage("Textures/thumbnails/frame_unselected.png");
    ImageFormat(&textures[25], UNCOMPRESSED_R8G8B8A8);
    frame_unselected = LoadTextureFromImage(textures[25]);
}

void renderBackground () {
    switch (background) {
        case BACKGROUND_UNSET:
            DrawTexture(background_mountains, 0, 0, WHITE);
            break;
        case MOUNTAIN:
            DrawTexture(background_mountain, 0, 0, WHITE);
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
}

void endOfGame () {
    DrawTexture(backButton_simple, backButtonX, backButtonY, WHITE);

    if (isOverButton(backButtonX, backButtonY, buttonWidth / 2, buttonHeight / 2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(backButton_clicked, backButtonX, backButtonY, WHITE);
        startTime = 0;
        gameState = MENU;
    }
}

void game () {
    renderBackground();

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

    if(!IsThereAnyBall())
        gameState = END;
}