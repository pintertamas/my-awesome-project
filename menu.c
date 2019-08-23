#include "menu.h"

void loadMenu () {
    textures[1] = LoadImage("Textures/background_900x600.png");                                                              // Loaded in CPU memory (RAM)
    ImageFormat(&textures[1], UNCOMPRESSED_R8G8B8A8);                                                         // Format image to RGBA 32bit (required for texture update)
    menuTexture = LoadTextureFromImage(textures[1]);                                                             // Image converted to texture, GPU memory (VRAM)
}

void renderMenu () {
    DrawTexture(menuTexture, 0, 0, WHITE);
}

void menu () {
    InitWindow(900, 600, "My Awesome Game's Menu");

    SetTargetFPS(60);
    loadMenu();

    while (!WindowShouldClose())                                                                                        // Detect window close button or ESC key
    {
        renderMenu();
        //-----------------------------------------------------
        BeginDrawing();
        ClearBackground(SKYBLUE);
        DrawFPS(10, 10);
        EndDrawing();
        //-----------------------------------------------------
    }
    CloseWindow();                                                                                                      // Close window and OpenGL context
}
