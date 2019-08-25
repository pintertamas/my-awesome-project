#include "menu.h"

void loadMenu () {
    textures[1] = LoadImage("Textures/background_blank.png");                                                  // Loaded in CPU memory (RAM)
    ImageFormat(&textures[1], UNCOMPRESSED_R8G8B8A8);                                                        // Format image to RGBA 32bit (required for texture update)
    menuBackground = LoadTextureFromImage(textures[1]);                                                             // Image converted to texture, GPU memory (VRAM)

    textures[2] = LoadImage("Textures/startButton_simple.png");                                                // Loaded in CPU memory (RAM)
    ImageFormat(&textures[2], UNCOMPRESSED_R8G8B8A8);                                                        // Format image to RGBA 32bit (required for texture update)
    startButton_simple = LoadTextureFromImage(textures[2]);                                                      // Image converted to texture, GPU memory (VRAM)

    textures[3] = LoadImage("Textures/startButton_clicked.png");                                               // Loaded in CPU memory (RAM)
    ImageFormat(&textures[3], UNCOMPRESSED_R8G8B8A8);                                                        // Format image to RGBA 32bit (required for texture update)
    startButton_clicked = LoadTextureFromImage(textures[3]);                                                     // Image converted to texture, GPU memory (VRAM)
}

void renderMenu () {

    double timePassed = GetTime();
    timePassed /= 2;
    DrawCircle(menu_screenWidth / 2 + 350 * sin(timePassed), menu_screenHeight / 2 + 200 * cos(timePassed), 50, YELLOW);

    //printf("%f\n", sin(timePassed));

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
        //DrawText("seggfasz", 100, 100, 100, PINK);
        return true;
    } else
        return false;
}

void buttonClick () {
    if(isOverButton(startButtonX, startButtonY, buttonWidth, buttonHeight) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DrawTexture(startButton_clicked, startButtonX, startButtonY, WHITE);
        startTime = clock();
    }
}

void renderButtons () {
    DrawTexture(startButton_simple, startButtonX, startButtonY, WHITE);

    int timeDiff = clock() - startTime;
    printf("%ld\n", startTime);
    if(startTime != 0) {
        if(timeDiff >= 0 && timeDiff < 1000)
            DrawText("3", menu_screenWidth / 2 - 15, menu_screenHeight / 3, 60, BLACK);
        else if(timeDiff >= 1000 && timeDiff < 2000)
            DrawText("2", menu_screenWidth / 2 - 15, menu_screenHeight / 3, 60, BLACK);
        else if(timeDiff >= 2000 && timeDiff < 3000)
            DrawText("1", menu_screenWidth / 2 - 15, menu_screenHeight / 3, 60, BLACK);
        else if(timeDiff >= 3000 && timeDiff < 5000)
            DrawText("LET'S GO", menu_screenWidth / 2 - 150, menu_screenHeight / 3, 60, BLACK);
        else CloseWindow();
    }
}

void menu () {
    menu_screenWidth = 900;
    menu_screenHeight = 600;
    buttonWidth = 150;
    buttonHeight = 80;
    BACKGROUND_COLOR.r = 0;
    BACKGROUND_COLOR.g = 210;
    BACKGROUND_COLOR.b = 255;

    startButtonX = menu_screenWidth / 2 - buttonWidth / 2;
    startButtonY = buttonHeight;

    InitWindow(menu_screenWidth, menu_screenHeight, "My Awesome Game's Menu");

    SetTargetFPS(60);
    loadMenu();

    while (!WindowShouldClose())                                                                                        // Detect window close button or ESC key
    {
        //DrawLine(menu_screenWidth / 2, 0, menu_screenWidth / 2, menu_screenHeight, PINK);

        renderMenu();
        renderButtons();
        buttonClick();
        //isOverButton(startButtonX, startButtonY, buttonWidth, buttonHeight);



        //-----------------------------------------------------
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);
        DrawFPS(10, 10);
        EndDrawing();
        //-----------------------------------------------------
    }
    CloseWindow();                                                                                                      // Close window and OpenGL context
}
