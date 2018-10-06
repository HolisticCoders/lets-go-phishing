#include "raylib.h"

#include "mail.h"
#include "victim.h"

#include "ui/board.h"
#include "ui/tweet.h"


// Keep this one AFTER all others to avoid redefinitions.
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


int main() {

    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Let's go phishing!");

    SetTargetFPS(30);

    Player player;
    GUI_Board board;
    board.setPlayer(&player);

    Victim victim;

    Tweet tweet(&victim, "Hello, this is a tweet");

    const int tweetCount = 5;
    GUI_Tweet GUI_tweets[tweetCount];

    // 1st tweet y position
    int y = 60;
    for(int i=0; i < tweetCount; i++) {

        GUI_tweets[i].setX(935);
        GUI_tweets[i].setY(y);
        GUI_tweets[i].setTweet(&tweet);
    
        y += GUI_tweets[i].height() + 10;
    }

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
            for (GUI_Tweet tweet: GUI_tweets){
                tweet.update();
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
