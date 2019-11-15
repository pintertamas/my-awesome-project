#ifndef MY_AWESOME_PROJECT_SCORES_H
#define MY_AWESOME_PROJECT_SCORES_H

typedef struct Score {
    int ballsDestroyed;
    int time;
    int difficulty;
}Score;

Score topScores[10];
int score_time;
void readFromFile (Score *scoreArray);
void writeToFile (Score *scoreArray);
void endOfGame (Score *scoreArray);
void scores(Score *scoreArray);

#endif //MY_AWESOME_PROJECT_SCORES_H