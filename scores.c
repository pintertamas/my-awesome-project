#include "scores.h"
#include "global.h"
#include "bullet.h"
#include "ball.h"
#include "buttons.h"
#include "menu.h"
#include "textures.h"
#include "settings.h"
#include "game.h"

int scoreArray[10][2];

void renderScores (int array[10][2], int x, int y, int fs, int textSpace) {
    for(int i = 0; i < 10; i++) {
        int min = (int)array[9-i][0] / 60;
        int sec = array[9-i][0] - 60 * min;

        Vector2 numberPosition;
        if(i == 9)
            numberPosition.x = x - 55;
        else
            numberPosition.x = x - 40;
        numberPosition.y = y + i * 30;
        Vector2 scorePosition = {x, y + i * 30};
        Vector2 difficultyPosition = {x + textSpace, y + i * 30};

        DrawTextEx(font, FormatText("%d: ", i+1), numberPosition, fs, 1, BLACK);
        if(min <= 10)
            DrawTextEx(font, FormatText("0%d:", min), scorePosition, fs, 1, BLACK);
        else
            DrawTextEx(font, FormatText("%d:", min), scorePosition, fs, 1, BLACK);
        scorePosition.x += 3 * fs / 2;
        if(sec < 10)
            DrawTextEx(font, FormatText("0%d ", sec), scorePosition, fs, 1, BLACK);
        else
            DrawTextEx(font, FormatText("%d ", sec), scorePosition, fs, 1, BLACK);

        switch (array[9-i][1]) {
            case 0:
                DrawTextEx(font, "-", difficultyPosition, fs, 1, BLACK);
                break;
            case 1:
                DrawTextEx(font, "EASY", difficultyPosition, fs, 1, BLACK);
                break;
            case 2:
                DrawTextEx(font, "MEDIUM", difficultyPosition, fs, 1, BLACK);
                break;
            case 3:
                DrawTextEx(font, "HARD", difficultyPosition, fs, 1, BLACK);
                break;
        }
    }
}

void writeToFile (int array[10][2]) {
    FILE *file;
    file = fopen("scores.txt", "wt");
    if(file == NULL) {
        perror("cannot open file");
        return;
    }
    for(int i = 0; i < 10; i++) {
        fprintf(file, "%d %d\n", array[i][0], array[i][1]);
    }
    fclose(file);
}

void readFromFile (int array[10][2]) {
    FILE *file;
    file = fopen("scores.txt", "rt");
    if(file == NULL) {
        perror("cannot read the file");
        return;
    }
    for(int i = 0; i < 10; i++) {
        fscanf(file, "%d", &array[i][0]);
        fscanf(file, "%d", &array[i][1]);
    }
    fclose(file);
}

void arraySort(int array[10][2]) {
    for (int i = 0; i < 9; ++i) {
        int min = i;
        for (int j = i+1; j < 10; ++j)
            if (array[j][0] < array[min][0])
                min = j;

        if (min != i) {
            int temp[2];
            temp[0] = array[min][0];
            temp[1] = array[min][1];
            array[min][0] = array[i][0];
            array[min][1] = array[i][1];
            array[i][0] = temp[0];
            array[i][1] = temp[1];
        }
    }
}

void updateScores (int array[10][2], int number) {
    int lowest = 1000000;
    int index = 0;
    for(int i = 0; i < 10; i++) {
        if(array[i][0] < lowest || array[i][0] == 0) {
            lowest = array[i][0];
            index = i;
        }
    }
    array[index][0] = number;
    if(gameDifficulty == EASY)
        array[index][1] = 1;
    else if(gameDifficulty == MEDIUM)
        array[index][1] = 2;
    else if(gameDifficulty == HARD)
        array[index][1] = 3;
}

void resetLeaderBoard () {
    for(int i = 0; i < 10; i++) {
        scoreArray[i][0] = 0;
        scoreArray[i][1] = 0;
    }
}

void endOfGame () {
    score_time = (int)((roundEnd - roundStart) / 1000);
    updateScores(scoreArray, score_time);
    arraySort(scoreArray);
    freeList_bullet();
    freeList_ball();
    while (!WindowShouldClose()) {
        DrawTexture(background_gameOver, 0, 0, WHITE);
        DrawTexture(backButton_simple, backButton.x, backButton.y, WHITE);


        renderScores(scoreArray, screenWidth/2 - 90, 330, 26, 140);

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

void renderScoresMenu () {
    DrawTexture(scoresLogo, menu_screenWidth / 2 - 230, 30, WHITE);
    DrawTexture(backButton_simple, backButton.x, backButton.y, WHITE);
    DrawTexture(crown, menu_screenWidth / 2 - 160, 152, WHITE);
}

void scoresMenuButtons () {
    if (isOverButton(backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(backButton_clicked, backButton.x, backButton.y, WHITE);
        gameState = MENU;
    }
    if(isOverButton(clearLeaderBoard) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(clear_clicked, clearLeaderBoard.x, clearLeaderBoard.y, WHITE);
        //resetLeaderBoard();
    } else {
        DrawTexture(clear_simple, clearLeaderBoard.x, clearLeaderBoard.y, WHITE);
    }
}

void scores() {
    arraySort(scoreArray);
    while (!WindowShouldClose()) {
        ClearBackground(settingsBackground);
        renderScoresMenu();
        scoresMenuButtons();
        renderScores(scoreArray, menu_screenWidth / 2 - 90, 150, 32, 100);

        if (gameState != SCORES)
            break;
        //-----------------------------------------------------
        BeginDrawing();
        EndDrawing();
        //-----------------------------------------------------
    }
}