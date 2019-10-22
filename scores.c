#include "scores.h"
#include "global.h"
#include "ball.h"
#include "buttons.h"
#include "menu.h"
#include "textures.h"
#include "settings.h"
#include "game.h"
#include "debugmalloc.h"

int scoreArray[10][3];

void renderTime (Vector2 position, int time, int fontSize) {
    int min = time / 60;
    int sec = time - 60 * min;

    if(sec == 0 && min == 0) {
        DrawTextEx(font, "  --:--", position, fontSize, 1, BLACK);
    } else {
        if(min <= 10)
            DrawTextEx(font, FormatText("0%d:", min), position, fontSize, 1, BLACK);
        else
            DrawTextEx(font, FormatText("%d:", min), position, fontSize, 1, BLACK);

        position.x += 3 * fontSize / 2;
        if(sec < 10)
            DrawTextEx(font, FormatText("0%d ", sec), position, fontSize, 1, BLACK);
        else
            DrawTextEx(font, FormatText("%d ", sec), position, fontSize, 1, BLACK);
    }
}

void renderScores (int array[10][3], int x, int y, int fs, int textSpace) {

    for(int i = 0; i < 10; i++) {                                                                                       //scores
        Vector2 numberPosition;
        if(i == 9)
            numberPosition.x = x - 55;
        else
            numberPosition.x = x - 40;
        numberPosition.y = y + i * 30;
        Vector2 timePosition = {x + 55, y + i * 30};
        Vector2 difficultyPosition = {x + textSpace + 55, y + i * 30};
        Vector2 ballCountPosition = {x, y + i * 30};

        DrawTextEx(font, FormatText("%d: ", i+1), numberPosition, fs, 1, BLACK);
        DrawTextEx(font, FormatText("%d", array[9-i][0]), ballCountPosition, fs, 1, BLACK);

        renderTime(timePosition, array[9-i][1], fs);

        switch (array[9-i][2]) {
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

void writeToFile (int array[10][3]) {
    FILE *file;
    file = fopen("../scores.txt", "wt");
    if(file == NULL) {
        perror("cannot open file");
        return;
    }
    for(int i = 0; i < 10; i++) {
        fprintf(file, "%d %d %d\n", array[i][0], array[i][1], array[i][2]);
    }
    fclose(file);
}

void readFromFile (int array[10][3]) {
    FILE *file;
    file = fopen("../scores.txt", "rt");
    if(file == NULL) {
        perror("cannot read the file");
        return;
    }
    for(int i = 0; i < 10; i++) {
        fscanf(file, "%d", &array[i][0]);
        fscanf(file, "%d", &array[i][1]);
        fscanf(file, "%d", &array[i][2]);
    }
    fclose(file);
}

void arraySort(int array[10][3]) {
    for (int i = 0; i < 9; ++i) {
        int min = i;
        for (int j = i+1; j < 10; ++j)
            if (array[j][0] < array[min][0])
                min = j;

        if (min != i) {
            int temp[3];
            temp[0] = array[min][0];
            temp[1] = array[min][1];
            temp[2] = array[min][2];
            array[min][0] = array[i][0];
            array[min][1] = array[i][1];
            array[min][2] = array[i][2];
            array[i][0] = temp[0];
            array[i][1] = temp[1];
            array[i][2] = temp[2];
        }
    }
}

void renderDifficulty (Vector2 where, int fontSize) {
    if(gameDifficulty == EASY)
        DrawTextEx(font, "Game difficulty:   EASY", where, fontSize,1, BLACK);
    else if(gameDifficulty == MEDIUM)
        DrawTextEx(font, "Game difficulty:  MEDIUM", where, fontSize,1, BLACK);
    else if(gameDifficulty == HARD)
        DrawTextEx(font, "Game difficulty:   HARD", where, fontSize,1, BLACK);
    else
        DrawTextEx(font, "Game difficulty:   UNSET", where, fontSize,1, BLACK);
}

void updateScores (int array[10][3], int number) {
    int lowest = 1000000;
    int index = 0;
    for(int i = 0; i < 10; i++) {
        if(array[i][0] < lowest || array[i][0] == 0) {
            lowest = array[i][0];
            index = i;
        }
    }
    array[index][0] = number;
    array[index][1] = score_time;
    array[index][2] = gameDifficulty;
}

void resetLeaderBoard () {
    for(int i = 0; i < 10; i++) {
        scoreArray[i][0] = 0;
        scoreArray[i][1] = 0;
        scoreArray[i][2] = 0;
    }
}

void endScreenButtons () {
    if (isOverButton(backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(backButton_clicked, backButton.x, backButton.y, WHITE);
        startTime = 0;
        gameState = MENU;
    }
    else if (isOverButton(restartButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        startTime = 0;
        gameState = GAME;
    }
}

void renderEnd() {
    DrawTexture(background_gameOver, 0, 0, WHITE);
    DrawTexture(backButton_simple, backButton.x, backButton.y, WHITE);
    DrawTexture(restartGameButton, restartButton.x, restartButton.y, WHITE);                                            //restartButton

    int gap = 55;
    Vector2 ballCountPosition = {screenWidth / 2 - 170, 550};
    Vector2 timePosition = {ballCountPosition.x, ballCountPosition.y - gap};
    Vector2 difficultyPosition = {timePosition.x, timePosition.y - gap};
    Vector2 damagePosition = {difficultyPosition.x, difficultyPosition.y - gap};
    int fontSize = 36;
    DrawTextEx(font, FormatText("Total balls popped:   %d", balls_destroyed), ballCountPosition, fontSize,1, BLACK);
    DrawTextEx(font, "Game time: ", timePosition, fontSize,1, BLACK);
    timePosition.x += 260;
    renderTime(timePosition, score_time, fontSize);
    renderDifficulty(difficultyPosition, fontSize);
    DrawTextEx(font, FormatText("Damage dealt:    %d", damageDealt), damagePosition, fontSize,1, BLACK);
}

void endOfGame () {
    score_time = (int)((roundEnd - roundStart) / 1000);
    updateScores(scoreArray, balls_destroyed);
    arraySort(scoreArray);
    while (!WindowShouldClose()) {
        renderEnd();
        endScreenButtons();

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
    DrawTexture(crown, menu_screenWidth / 2 - 165, 152, WHITE);
}

void scoresMenuButtons () {
    if (isOverButton(backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(backButton_clicked, backButton.x, backButton.y, WHITE);
        gameState = MENU;
    }
    if(isOverButton(clearLeaderBoard) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(clear_clicked, clearLeaderBoard.x, clearLeaderBoard.y, WHITE);
        resetLeaderBoard();
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
        renderScores(scoreArray, menu_screenWidth / 2 - 100, 150, 32, 100);

        if (gameState != SCORES)
            break;
        //-----------------------------------------------------
        BeginDrawing();
        EndDrawing();
        //-----------------------------------------------------
    }
}