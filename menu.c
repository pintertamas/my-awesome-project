#include "menu.h"

void loadMenu () {
    textures[1] = LoadImage("Textures/background_blank.png");                                                  // Loaded in CPU memory (RAM)
    ImageFormat(&textures[1], UNCOMPRESSED_R8G8B8A8);                                                        // Format image to RGBA 32bit (required for texture update)
    menuTexture = LoadTextureFromImage(textures[1]);                                                             // Image converted to texture, GPU memory (VRAM)
}

void renderMenu () {

    double timePassed = GetTime();
    timePassed /= 2;
    DrawCircle(menu_screenWidth / 2 + 350 * sin(timePassed), menu_screenHeight + 200 * cos(timePassed), 50, YELLOW);

    printf("%f\n", sin(timePassed));

    if(((sin(timePassed) < 0 && cos(timePassed) > 0) || (sin(timePassed) > 0 && cos(timePassed) > 0)) && BACKGROUND_COLOR.g > 0) {
        BACKGROUND_COLOR.g--;
        BACKGROUND_COLOR.b--;
    } else if(BACKGROUND_COLOR.b < 255) {
        BACKGROUND_COLOR.g++;
        BACKGROUND_COLOR.b++;
    }

    DrawTexture(menuTexture, 0, 0, WHITE);
}

void renderButtons () {
    int startButtonX = menu_screenWidth / 2 - buttonWidth / 2;
    int startButtonY = menu_screenHeight / 3;
}

void menu () {
    menu_screenWidth = 900;
    menu_screenHeight = 300;
    buttonWidth = 100;
    buttonHeight = 40;
    BACKGROUND_COLOR.r = 0;
    BACKGROUND_COLOR.g = 210;
    BACKGROUND_COLOR.b = 255;

    InitWindow(900, 600, "My Awesome Game's Menu");

    SetTargetFPS(60);
    loadMenu();

    while (!WindowShouldClose())                                                                                        // Detect window close button or ESC key
    {
        renderMenu();
        //-----------------------------------------------------
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);
        DrawFPS(10, 10);
        EndDrawing();
        //-----------------------------------------------------
    }
    CloseWindow();                                                                                                      // Close window and OpenGL context
}
