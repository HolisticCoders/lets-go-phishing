#include <string>

#include "raylib.h"
#include "raygui.h"

#include "../player.h"
#include "board.h"
#include "button.h"


GUI_Board::GUI_Board() : m_player{nullptr} {
    m_buttons[0] = new GUI_Button(
        "E-Mail 01",
        (Rectangle){ 35, 655, 93, 30 }
    );
    m_buttons[1] = new GUI_Button(
        "E-Mail 02",
        (Rectangle){ 138, 655, 93, 30 }
    );
    m_buttons[2] = new GUI_Button(
        "E-Mail 03",
        (Rectangle){ 241, 655, 93, 30 }
    );
    m_buttons[3] = new GUI_Button(
        "E-Mail 04",
        (Rectangle){ 344, 655, 93, 30 }
    );
}


GUI_Board::GUI_Board(Player* player) : m_player{player} {
    m_buttons[0] = new GUI_Button(
        "E-Mail 01",
        (Rectangle){ 35, 655, 93, 30 }
    );
    m_buttons[1] = new GUI_Button(
        "E-Mail 02",
        (Rectangle){ 138, 655, 93, 30 }
    );
    m_buttons[2] = new GUI_Button(
        "E-Mail 03",
        (Rectangle){ 241, 655, 93, 30 }
    );
    m_buttons[3] = new GUI_Button(
        "E-Mail 04",
        (Rectangle){ 344, 655, 93, 30 }
    );
}


GUI_Board::~GUI_Board() {
    for (GUI_Button* button: m_buttons) {
        if (button) {
            delete button;
        }
    }
}


void GUI_Board::update() {
    if (GuiWindowBox((Rectangle){ 0, 0, 1280, 720 }, "Let's go phishing!")) {
        setClosing(true);
    }
    GuiGroupBox((Rectangle){ 925, 50, 330, 550 }, "Twatter");
    GuiGroupBox((Rectangle){ 475, 50, 425, 645 }, "Profile");
    GuiGroupBox((Rectangle){ 25, 50, 425, 570 }, "Send");
    GuiGroupBox((Rectangle){ 25, 645, 425, 50 }, "Emails");
    GuiGroupBox((Rectangle){ 925, 625, 330, 70 }, "Stats");

    GuiLabel((Rectangle){ 935, 635, 36, 25 }, "Money:");
    GuiLabel((Rectangle){ 935, 655, 71, 25 }, "Wanted level:");

    GuiSliderBar((Rectangle){ 1045, 660, 185, 15 }, m_player->wantedLevel(), 0, 100);

    const char* money = std::to_string(m_player->money()).c_str();
    GuiLabel((Rectangle){ 1045, 635, 161, 25 }, money);

    for (GUI_Button* button: m_buttons) {
        if (!button) {
            continue;
        }
        button->update();
    }

    if (m_mail) {
        DrawText(m_mail->title().c_str(), 35, 60, 12, (Color){ 63, 63, 63, 255 });
    }
}


// Draw mails and attache them to buttons
// until we have four mails available.
void GUI_Board::drawMails() {
    
}
