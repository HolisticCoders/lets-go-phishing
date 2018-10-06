#include "raylib.h"

#include "mail.h"
#include "victim.h"

#include "ui/board.h"

// Keep this one AFTER all others to avoid redefinitions.
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


int main() {

    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Let's go phishing!");

    SetTargetFPS(30);

    Player player;
    GUI_Board board(&player);

    Victim victim;

    while (true) {

        if (WindowShouldClose() || board.closing()) {
            // TODO: User message box confirmation.
            break;
        }
        if (player.wantedLevel() >= 100) {
            // TODO: Game Over panel then quit.
            break;
        }

        BeginDrawing();

            ClearBackground(GetColor(style[DEFAULT_BACKGROUND_COLOR]));

            board.update();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
