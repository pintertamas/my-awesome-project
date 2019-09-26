#include "buttons.h"
#include "global.h"

void setupButtons () {

    buttonWidth = 150;
    buttonHeight = 80;

    startButton.x = menu_screenWidth / 2 - buttonWidth / 2;
    startButton.y = buttonHeight / 4;
    startButton.w = buttonWidth;
    startButton.h = buttonHeight;

    scoresButton.x = startButton.x;
    scoresButton.y = startButton.y + buttonHeight + buttonHeight / 6;
    scoresButton.w = buttonWidth;
    scoresButton.h = buttonHeight;

    settingsButton.x = menu_screenWidth - buttonHeight / 2 - buttonHeight / 4;
    settingsButton.y = buttonHeight / 4;
    settingsButton.w = buttonHeight / 2;
    settingsButton.h = buttonHeight / 2;

    backButton.x = buttonHeight / 4;
    backButton.y = buttonHeight / 4;
    backButton.w = buttonHeight / 2;
    backButton.h = buttonHeight / 2;

    clearLeaderBoard.x = menu_screenWidth / 2 - buttonWidth / 2;
    clearLeaderBoard.y = menu_screenHeight - 3 * buttonWidth / 4;
    clearLeaderBoard.w = buttonWidth;
    clearLeaderBoard.h = buttonHeight;

    restartButton.x = screenWidth / 2 - buttonHeight / 2;
    restartButton.y = 700;
    restartButton.w = 1.5*buttonHeight;
    restartButton.h = 1.5*buttonHeight;

    easyButton.x = buttonWidth / 2;
    easyButton.y = buttonHeight + buttonHeight / 2;
    easyButton.w = buttonWidth;
    easyButton.h = buttonHeight;
    mediumButton.x = menu_screenWidth / 2 - buttonWidth / 2;
    mediumButton.y = buttonHeight + buttonHeight / 2;
    mediumButton.w = buttonWidth;
    mediumButton.h = buttonHeight;
    hardButton.x = menu_screenWidth - buttonWidth - buttonWidth / 2;
    hardButton.y = buttonHeight + buttonHeight / 2;
    hardButton.w = buttonWidth;
    hardButton.h = buttonHeight;

    int thumbnailWidth = 133;
    int thumbnailHeight = 200;
    int gap = (menu_screenWidth - 4 * thumbnailWidth) / 5;

    forest.x = gap;
    forest.y = menu_screenHeight - thumbnailHeight - 80;
    forest.w = thumbnailWidth;
    forest.h = thumbnailHeight;
    mountains.x = thumbnailWidth + 2 * gap;
    mountains.y = menu_screenHeight - thumbnailHeight - 80;
    mountains.w = thumbnailWidth;
    mountains.h = thumbnailHeight;
    japan.x = 2 * thumbnailWidth + 3 * gap;
    japan.y = menu_screenHeight - thumbnailHeight - 80;
    japan.w = thumbnailWidth;
    japan.h = thumbnailHeight;
    space.x = 3 * thumbnailWidth + 4 * gap;
    space.y = menu_screenHeight - thumbnailHeight - 80;
    space.w = thumbnailWidth;
    space.h = thumbnailHeight;
}