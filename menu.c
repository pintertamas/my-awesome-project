#include "menu.h"

void loadMenuImages () {
    textures[1] = LoadImage("Textures/backgrounds/background_blank.png");                                      // Loaded in CPU memory (RAM)
    ImageFormat(&textures[1], UNCOMPRESSED_R8G8B8A8);                                                        // Format image to RGBA 32bit (required for texture update)
    menuBackground = LoadTextureFromImage(textures[1]);                                                          // Image converted to texture, GPU memory (VRAM)

    textures[2] = LoadImage("Textures/buttons/startButton_simple.png");
    ImageFormat(&textures[2], UNCOMPRESSED_R8G8B8A8);
    startButton_simple = LoadTextureFromImage(textures[2]);

    textures[3] = LoadImage("Textures/buttons/startButton_clicked.png");
    ImageFormat(&textures[3], UNCOMPRESSED_R8G8B8A8);
    startButton_clicked = LoadTextureFromImage(textures[3]);

    textures[5] = LoadImage("Textures/buttons/settingsButton_simple.png");
    ImageFormat(&textures[5], UNCOMPRESSED_R8G8B8A8);
    settingsButton_simple = LoadTextureFromImage(textures[5]);

    textures[6] = LoadImage("Textures/buttons/settingsButton_clicked.png");
    ImageFormat(&textures[6], UNCOMPRESSED_R8G8B8A8);
    settingsButton_clicked = LoadTextureFromImage(textures[6]);

    textures[7] = LoadImage("Textures/buttons/scoresButton_simple.png");
    ImageFormat(&textures[7], UNCOMPRESSED_R8G8B8A8);
    scoresButton_simple = LoadTextureFromImage(textures[7]);

    textures[8] = LoadImage("Textures/buttons/scoresButton_clicked.png");
    ImageFormat(&textures[8], UNCOMPRESSED_R8G8B8A8);
    scoresButton_clicked = LoadTextureFromImage(textures[8]);

    textures[10] = LoadImage("Textures/buttons/easyMode.png");
    ImageFormat(&textures[10], UNCOMPRESSED_R8G8B8A8);
    easyMode = LoadTextureFromImage(textures[10]);

    textures[11] = LoadImage("Textures/buttons/mediumMode.png");
    ImageFormat(&textures[11], UNCOMPRESSED_R8G8B8A8);
    mediumMode = LoadTextureFromImage(textures[11]);

    textures[12] = LoadImage("Textures/buttons/hardMode.png");
    ImageFormat(&textures[12], UNCOMPRESSED_R8G8B8A8);
    hardMode = LoadTextureFromImage(textures[12]);

    textures[13] = LoadImage("Textures/buttons/easyMode_selected.png");
    ImageFormat(&textures[13], UNCOMPRESSED_R8G8B8A8);
    easyMode_selected = LoadTextureFromImage(textures[13]);

    textures[12] = LoadImage("Textures/buttons/mediumMode_selected.png");
    ImageFormat(&textures[12], UNCOMPRESSED_R8G8B8A8);
    mediumMode_selected = LoadTextureFromImage(textures[12]);

    textures[12] = LoadImage("Textures/buttons/hardMode_selected.png");
    ImageFormat(&textures[12], UNCOMPRESSED_R8G8B8A8);
    hardMode_selected = LoadTextureFromImage(textures[12]);

    textures[13] = LoadImage("Textures/buttons/hardMode_selected.png");
    ImageFormat(&textures[13], UNCOMPRESSED_R8G8B8A8);
    hardMode_selected = LoadTextureFromImage(textures[13]);

    textures[14] = LoadImage("Textures/buttons/hardMode_selected.png");
    ImageFormat(&textures[14], UNCOMPRESSED_R8G8B8A8);
    hardMode_selected = LoadTextureFromImage(textures[14]);

}

void renderMenu () {

    double timePassed = GetTime();
    timePassed /= 2;
    DrawCircle(menu_screenWidth / 2 + 350 * sin(timePassed), menu_screenHeight / 2 + 200 * cos(timePassed), 50, YELLOW);

    if(((sin(timePassed) < 0 && cos(timePassed) > 0) || (sin(timePassed) > 0 && cos(timePassed) > 0)) && BACKGROUND_COLOR.g > 0) {
        BACKGROUND_COLOR.g--;
        BACKGROUND_COLOR.b--;
    } else if(BACKGROUND_COLOR.b < 255) {
        BACKGROUND_COLOR.g++;
        BACKGROUND_COLOR.b++;
    }

    DrawTexture(menuBackground, 0, 0, WHITE);
}

bool isOverButton (int x, int y, int w, int h) {
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();

    if(mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h) {
        return true;
    } else
        return false;
}

void menuButtonClick () {
    if(isOverButton(startButtonX, startButtonY, buttonWidth, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(startButton_clicked, startButtonX, startButtonY, WHITE);
        startTime = clock();
    }
    if(isOverButton(settingsButtonX, settingsButtonY, buttonHeight / 2, buttonHeight / 2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(settingsButton_clicked, settingsButtonX, settingsButtonY, WHITE);
        gameState = SETTINGS;
    }
    if(isOverButton(scoresButtonX, scoresButtonY, buttonWidth, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(scoresButton_clicked, scoresButtonX, scoresButtonY, WHITE);
    }
}

void renderButtons () {
    DrawTexture(startButton_simple, startButtonX, startButtonY, WHITE);
    DrawTexture(scoresButton_simple, scoresButtonX, scoresButtonY, WHITE);
    DrawTexture(settingsButton_simple, settingsButtonX, settingsButtonY, WHITE);

    int timeDiff = clock() - startTime;
    //printf("%ld\n", startTime);
    if(startTime != 0) {
        if(timeDiff >= 0 && timeDiff < 1000)
            DrawText("3", menu_screenWidth / 2 - 15, menu_screenHeight / 3, 60, BLACK);
        else if(timeDiff >= 1000 && timeDiff < 2000)
            DrawText("2", menu_screenWidth / 2 - 15, menu_screenHeight / 3, 60, BLACK);
        else if(timeDiff >= 2000 && timeDiff < 3000)
            DrawText("1", menu_screenWidth / 2 - 15, menu_screenHeight / 3, 60, BLACK);
        else if(timeDiff >= 3000 && timeDiff < 4000)
            DrawText("LET'S GO", menu_screenWidth / 2 - 150, menu_screenHeight / 3, 60, BLACK);
        else {
            gameState = GAME;
        }
    }
}

void menu () {

    startButtonX = menu_screenWidth / 2 - buttonWidth / 2;
    startButtonY = buttonHeight / 4;

    scoresButtonX = startButtonX;
    scoresButtonY = startButtonY + buttonHeight + buttonHeight / 6;

    settingsButtonX = menu_screenWidth - buttonHeight / 2 - buttonHeight / 4;
    settingsButtonY = buttonHeight / 4;

    renderMenu();
    renderButtons();
    menuButtonClick();
}