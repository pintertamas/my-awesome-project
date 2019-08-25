#include "menu.h"

void loadMenuImages () {
    textures[1] = LoadImage("Textures/background_blank.png");                                                  // Loaded in CPU memory (RAM)
    ImageFormat(&textures[1], UNCOMPRESSED_R8G8B8A8);                                                        // Format image to RGBA 32bit (required for texture update)
    menuBackground = LoadTextureFromImage(textures[1]);                                                             // Image converted to texture, GPU memory (VRAM)

    textures[2] = LoadImage("Textures/startButton_simple.png");                                                // Loaded in CPU memory (RAM)
    ImageFormat(&textures[2], UNCOMPRESSED_R8G8B8A8);                                                        // Format image to RGBA 32bit (required for texture update)
    startButton_simple = LoadTextureFromImage(textures[2]);                                                      // Image converted to texture, GPU memory (VRAM)

    textures[3] = LoadImage("Textures/startButton_clicked.png");                                               // Loaded in CPU memory (RAM)
    ImageFormat(&textures[3], UNCOMPRESSED_R8G8B8A8);                                                        // Format image to RGBA 32bit (required for texture update)
    startButton_clicked = LoadTextureFromImage(textures[3]);                                                     // Image converted to texture, GPU memory (VRAM)

    textures[5] = LoadImage("Textures/settingsButton_simple.png");                                             // Loaded in CPU memory (RAM)
    ImageFormat(&textures[5], UNCOMPRESSED_R8G8B8A8);                                                        // Format image to RGBA 32bit (required for texture update)
    settingsButton_simple = LoadTextureFromImage(textures[5]);                                                   // Image converted to texture, GPU memory (VRAM)

    textures[6] = LoadImage("Textures/settingsButton_clicked.png");                                            // Loaded in CPU memory (RAM)
    ImageFormat(&textures[6], UNCOMPRESSED_R8G8B8A8);                                                        // Format image to RGBA 32bit (required for texture update)
    settingsButton_clicked = LoadTextureFromImage(textures[6]);                                                  // Image converted to texture, GPU memory (VRAM)

    textures[7] = LoadImage("Textures/scoresButton_simple.png");                                            // Loaded in CPU memory (RAM)
    ImageFormat(&textures[7], UNCOMPRESSED_R8G8B8A8);                                                        // Format image to RGBA 32bit (required for texture update)
    scoresButton_simple = LoadTextureFromImage(textures[7]);                                                  // Image converted to texture, GPU memory (VRAM)

    textures[8] = LoadImage("Textures/scoresButton_clicked.png");                                            // Loaded in CPU memory (RAM)
    ImageFormat(&textures[8], UNCOMPRESSED_R8G8B8A8);                                                        // Format image to RGBA 32bit (required for texture update)
    scoresButton_clicked = LoadTextureFromImage(textures[8]);                                                  // Image converted to texture, GPU memory (VRAM)

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

void buttonClick () {
    if(isOverButton(startButtonX, startButtonY, buttonWidth, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(startButton_clicked, startButtonX, startButtonY, WHITE);
        startTime = clock();
    }
    if(isOverButton(settingsButtonX, settingsButtonY, buttonHeight, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(settingsButton_clicked, settingsButtonX, settingsButtonY, WHITE);
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

    settingsButtonX = menu_screenWidth - 1.5 * buttonHeight;
    settingsButtonY = .5 * buttonHeight;

    //DrawLine(menu_screenWidth / 2, 0, menu_screenWidth / 2, menu_screenHeight, PINK);

    renderMenu();
    renderButtons();
    buttonClick();
}