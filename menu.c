#include "menu.h"

void menu () {
    InitWindow(900, 600, "My Awesome Game's Menu");
    SetTargetFPS(60);

    while (!WindowShouldClose())                                                                                        // Detect window close button or ESC key
    {

        //-----------------------------------------------------
        BeginDrawing();
        ClearBackground(SKYBLUE);
        DrawFPS(10, 10);
        EndDrawing();
        //-----------------------------------------------------
    }
    CloseWindow();                                                                                                      // Close window and OpenGL context
}
