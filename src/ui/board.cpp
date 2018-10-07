#include <iostream>
#include <fstream>
#include <string>

#include "json.hpp"
#include "raylib.h"
#include "raygui.h"

#include "../manager.h"

// gui includes
#include "board.h"
#include "button.h"
#include "profile.h"


using namespace std;
using namespace nlohmann;


GUI_Board::GUI_Board() {
    // button setup
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

    for (GUI_Button* button: m_buttons) {
        button->setBoard(*this);
    }

    // tweets setup
    // 1st tweet y position
    int y = 60;
    for (int i = 0; i < 5; i++) {
        m_guiTweets[i] = new GUI_Tweet();
        m_guiTweets[i]->setX(935);
        m_guiTweets[i]->setY(y);
        y += m_guiTweets[i]->height() + 10;
    }

    // mail setup
    m_guiMail = new GUI_Mail(this);

    // profile setup
    m_guiProfile = new GUI_Profile();

    m_manager = &Manager::getInstance();
}


GUI_Board::~GUI_Board() {
    delete m_guiMail;
    for (GUI_Button* button: m_buttons) {
        if (button) {
            delete button;
        }
    }
    for (int i = 0; i < 5; i++) {
        delete m_guiTweets[i];
    }
}


void GUI_Board::endTurn() {
    drawMails();
    drawTweets();
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

    if (m_manager->player()) {
        GuiSliderBar((Rectangle){ 1045, 660, 185, 15 }, m_manager->player()->wantedLevel(), 0, 100);
        const char* money = std::to_string(m_manager->player()->money()).c_str();
        GuiLabel((Rectangle){ 1045, 635, 161, 25 }, money);
    }

    for (GUI_Button* button: m_buttons) {
        if (!button) {
            continue;
        }
        button->update();
    }

    m_guiMail->update();
    m_guiProfile->update();

    for (int i=0; i<5; i++)
        m_guiTweets[i]->update();

}


// Draw mails and attach them to buttons
// until we have four mails available.
void GUI_Board::drawMails() {
    for (GUI_Button* button: m_buttons) {
        if (button->mail()) {
            continue;
        }
        int index = GetRandomValue(0, m_manager->mailCount() - 1);
        Mail* mail = &m_manager->mails()[index];
        button->setMail(mail);
    }
}


void GUI_Board::drawTweets() {
    for (GUI_Tweet* guiTweet: m_guiTweets) {
        int index = GetRandomValue(0, m_manager->tweetCount() - 1);
        Tweet* tweet = &m_manager->tweets()[index];
        guiTweet->setTweet(tweet);
    }
}

