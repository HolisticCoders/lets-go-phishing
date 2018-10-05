/*******************************************************************************************
*
*   window - tool description
*
*   LICENSE: zlib/libpng
*
*   Copyright (c) 2018 raylib technologies
*
**********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


int main() {

    const int screenWidth = 960;
    const int screenHeight = 540;

    InitWindow(screenWidth, screenHeight, "Let's go phishing!");

    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        BeginDrawing();

            ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
