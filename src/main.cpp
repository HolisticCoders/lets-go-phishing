#include "raylib.h"

#include "mail.cpp"
#include "ui/board.cpp"


int main() {

    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Let's go phishing!");

    SetTargetFPS(30);

    Player player;
    GUI_Board board;
    board.setPlayer(&player);

    while (!WindowShouldClose() || !board.closing()) {

        BeginDrawing();

            ClearBackground(GetColor(style[DEFAULT_BACKGROUND_COLOR]));

            board.update();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
