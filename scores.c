#include "scores.h"
#include "global.h"
#include "ball.h"
#include "buttons.h"
#include "menu.h"
#include "textures.h"
#include "settings.h"
#include "game.h"
#include "debugmalloc.h"

Score topScores[10];

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

void renderScores (Score scoreArray[10], int x, int y, int fs, int textSpace) {
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
        DrawTextEx(font, FormatText("%d", scoreArray[9-i].ballsDestroyed), ballCountPosition, fs, 1, BLACK);

        renderTime(timePosition, scoreArray[9-i].time, fs);

        switch (scoreArray[9-i].difficulty) {
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

void writeToFile (Score scoreArray[10]) {
    FILE *file;
    file = fopen("../scores.txt", "wt");
    if(file == NULL) {
        perror("cannot open file");
        return;
    }
    for(int i = 0; i < 10; i++) {
        fprintf(file, "%d %d %d\n", scoreArray[i].ballsDestroyed, scoreArray[i].time, scoreArray[i].difficulty);
    }
    fclose(file);
}

void readFromFile (Score scoreArray[10]) {
    FILE *file;
    file = fopen("../scores.txt", "rt");
    if(file == NULL) {
        perror("cannot read the file");
        return;
    }
    for(int i = 0; i < 10; i++) {
        fscanf(file, "%d %d %d", &scoreArray[i].ballsDestroyed, &scoreArray[i].time, &scoreArray[i].difficulty);
    }
    fclose(file);
}

void arraySort(Score scoreArray[10]) {
    for (int i = 0; i < 9; ++i) {
        int min = i;
        for (int j = i+1; j < 10; ++j)
            if (scoreArray[j].ballsDestroyed < scoreArray[min].ballsDestroyed)
                min = j;

        if (min != i) {
            Score temp;
            temp = scoreArray[min];
            scoreArray[min] = scoreArray[i];
            scoreArray[i] = temp;
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

void updateScores (Score scoreArray[10], int number) {
    int lowest = 1000000;
    int index = 0;
    for(int i = 0; i < 10; i++) {
        if(scoreArray[i].ballsDestroyed < lowest || scoreArray[i].ballsDestroyed == 0) {
            lowest = scoreArray[i].ballsDestroyed;
            index = i;
        }
    }
    scoreArray[index].ballsDestroyed = number;
    scoreArray[index].time = score_time;
    scoreArray[index].difficulty = gameDifficulty;
}

void resetLeaderBoard (Score scoreArray[10]) {
    for(int i = 0; i < 10; i++) {
        scoreArray[i].ballsDestroyed = 0;
        scoreArray[i].time = 0;
        scoreArray[i].difficulty = 0;
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
    DrawTextEx(font, FormatText("Total balls popped:   %d", ballProps.balls_destroyed), ballCountPosition, fontSize,1, BLACK);
    DrawTextEx(font, "Game time: ", timePosition, fontSize,1, BLACK);
    timePosition.x += 260;
    renderTime(timePosition, score_time, fontSize);
    renderDifficulty(difficultyPosition, fontSize);
    DrawTextEx(font, FormatText("Damage dealt:    %d", ballProps.damageDealt), damagePosition, fontSize,1, BLACK);
}

void endOfGame (Score scoreArray[10]) {
    score_time = (int)((roundEnd - roundStart) / 1000);
    updateScores(scoreArray, ballProps.balls_destroyed);
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

void scoresMenuButtons (Score scoreArray[10]) {
    if (isOverButton(backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(backButton_clicked, backButton.x, backButton.y, WHITE);
        gameState = MENU;
    }
    if(isOverButton(clearLeaderBoard) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(clear_clicked, clearLeaderBoard.x, clearLeaderBoard.y, WHITE);
        resetLeaderBoard(scoreArray);
    } else {
        DrawTexture(clear_simple, clearLeaderBoard.x, clearLeaderBoard.y, WHITE);
    }
}

void scores(Score scoreArray[10]) {
    arraySort(scoreArray);
    while (!WindowShouldClose()) {
        ClearBackground(settingsBackground);
        renderScoresMenu();
        scoresMenuButtons(scoreArray);
        renderScores(scoreArray, menu_screenWidth / 2 - 100, 150, 32, 100);

        if (gameState != SCORES)
            break;
        //-----------------------------------------------------
        BeginDrawing();
        EndDrawing();
        //-----------------------------------------------------
    }
}