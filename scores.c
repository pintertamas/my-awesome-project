#include "scores.h"
#include "global.h"
#include "bullet.h"
#include "ball.h"
#include "menu.h"
#include "textures.h"

void writeToFile (int array[10][2]) {
    FILE *fp;
    fp = fopen("scores.txt", "wt");
    if(fp == NULL) {
        perror("cannot open file");
        return;
    }
    for(int i = 0; i < 10; i++) {
        fprintf(fp, "%d ", i+1);
        if(array[i][0] >= 60) {
            int min = array[i][0] / 60;
            int sec = array[i][0] - 60 * min;
            fprintf(fp, "%d:%d ", min, sec);
        }
        switch (array[i][1]) {
            case 0:
                fprintf(fp, "EASY\n");
                break;
            case 1:
                fprintf(fp, "MEDIUM\n");
                break;
            case 2:
                fprintf(fp, "HARD\n");
                break;
        }
    }
}

void endOfGame () {
    Color settingsBackground = {0,190,255};
    freeList_bullet();
    freeList_ball();
    while (!WindowShouldClose()) {
        DrawTexture(background_gameOver, 0, 0, WHITE);
        DrawTexture(backButton_simple, backButton.x, backButton.y, WHITE);
        //Vector2 scorePosition = {210,330};
        //DrawTextEx(font, "1. xx:xx - \"difficulty\"\n2. xx:xx - \"difficulty\"\n3. xx:xx - \"difficulty\"\n", scorePosition, 20, 2, BLACK);

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

void scores() {
    int testarray[10][2];
    for(int i = 0; i < 10; i++) {
        testarray[i][0] = 100;
        testarray[i][1] = 0;
    }


    writeToFile(testarray);
    while (!WindowShouldClose()) {
        ClearBackground(BACKGROUND_COLOR);


        if (gameState != SCORES)
            break;
        //-----------------------------------------------------
        BeginDrawing();
        EndDrawing();
        //-----------------------------------------------------
    }
}