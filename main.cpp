#include "raylib.h"
#include "player.cpp"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


int main() {

    const int screenWidth = 960;
    const int screenHeight = 540;

    InitWindow(screenWidth, screenHeight, "Let's go phishing!");

    SetTargetFPS(30);

    Player player;

    while (!WindowShouldClose() && player.wantedLevel() < 100) {

        BeginDrawing();

            ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
