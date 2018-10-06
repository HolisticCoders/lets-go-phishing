#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "player.cpp"
#include "mail.cpp"


int main() {

    const int screenWidth = 960;
    const int screenHeight = 540;

    InitWindow(screenWidth, screenHeight, "Let's go phishing!");

    SetTargetFPS(30);

    Player player;

    // Initialize the spam e-mails.
    constexpr unsigned int mailCount = 4;
    Mail mails[mailCount];
    mails[0].setTitle("What a deal!");
    mails[0].setContent("Hesitate no longer, this awesome gaming PC should be yours today!");
    mails[0].setCategory(Products);
    mails[1].setTitle("Have you met Ted ?");
    mails[1].setContent("Lonely, handsome singles in the bar next door!");
    mails[1].setCategory(Dating);
    mails[2].setTitle("Cross the street and get a job!");
    mails[2].setContent("Long past are the days of boredom and poverty, follow my advice and get a job fitting your skills today!");
    mails[2].setCategory(Jobs);
    mails[3].setTitle("Don't let the virus spread!");
    mails[3].setContent("PLEASE READ THIS E-MAIL CAREFULLY!!! The ebola virus is coming back, you MUST take this medecine or risk being exposed and DIE!!!");
    mails[3].setCategory(HealthCare);

    while (!WindowShouldClose() && player.wantedLevel() < 100) {

        BeginDrawing();

            ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
