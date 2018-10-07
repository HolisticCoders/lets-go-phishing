#include <iostream>
#include <fstream>
#include <string>

#include "json.hpp"
#include "raylib.h"
#include "raygui.h"

#include "../player.h"
#include "../mail.h"
#include "../victim.h"

// gui includes
#include "board.h"
#include "button.h"
#include "profile.h"


using namespace std;
using namespace nlohmann;


GUI_Board::GUI_Board(Player* player) : m_player{player} {
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

    // TODO dynamically load victims
    m_victim = new Victim();
    m_victim->setName("Jean Eude");

    // tweets setup
    // 1st tweet y position
    int y = 60;
    for (int i = 0; i < 5; i++) {
<<<<<<< Updated upstream
        /* m_tweets[i] = new Tweet(); */
=======
        m_tweets[i] = new Tweet();
        m_tweets[i]->setAuthor(m_victim);
>>>>>>> Stashed changes
        m_guiTweets[i] = new GUI_Tweet();
        /* m_guiTweets[i]->setTweet(m_tweets[i]); */
        m_guiTweets[i]->setX(935);
        m_guiTweets[i]->setY(y);
        y += m_guiTweets[i]->height() + 10;
    }

    // Resource access setup.
    m_resources = new Resources("../resources/");

    // mail setup
    m_guiMail = new GUI_Mail(this);
    m_guiMail->setMail(m_mail);

    // profile setup
    m_guiProfile = new GUI_Profile();
    m_guiProfile->setVictim(m_victim);
}


GUI_Board::~GUI_Board() {
    delete m_resources;
    delete m_guiMail;
    delete m_victim;
    for (GUI_Button* button: m_buttons) {
        if (button) {
            delete button;
        }
    }
    for (int i = 0; i < 5; i++) {
        delete m_tweets[i];
        delete m_guiTweets[i];
    }
}


void GUI_Board::endTurn() {
    Victim* victim = m_guiProfile->victim();
    Mail* mail = m_guiMail->mail();
    cout << "Sending mail " << mail->title() << " to " << victim->name() << endl;
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

    drawMails();
    drawTweets();

    for (GUI_Button* button: m_buttons) {
        if (!button) {
            continue;
        }
        button->update();
    }

    if (m_mail)
        m_guiMail->update();
    if (m_guiProfile)
        m_guiProfile->update();

    for (int i=0; i<5; i++)
        m_guiTweets[i]->update();

}


void GUI_Board::loadData() {
    
}


// Draw mails and attach them to buttons
// until we have four mails available.
void GUI_Board::drawMails() {
    for (GUI_Button* button: m_buttons) {
        if (button->mail()) {
            continue;
        }
        cout << "Drawing mail for button " << button->label() << endl;
        json data = m_resources->getResource("mails.json");
        if (data.size() <= 0) {
            cout << "No mail could be drawn." << endl;
            return;
        }
        int index = GetRandomValue(0, data.size() - 1);
        Mail* mail = new Mail(
            data[index]["title"],
            data[index]["content"],
            data[index]["category"]
        );
        button->setMail(mail);
    }
}


void GUI_Board::drawTweets() {
    for (GUI_Tweet* tweet: m_guiTweets) {
        if (tweet->tweet()) {
            continue;
        }
        cout << "Drawing content for tweet." << endl;
        json data = m_resources->getResource("tweets.json");
        if (data.size() <= 0) {
            cout << "No tweet could be drawn." << endl;
            return;
        }
        int index = GetRandomValue(0, data.size() - 1);
        const string victimName = data[index]["author"];
        const string content = data[index]["content"];

        // Find the victim in the victims.json.
        Victim* victim = new Victim();
        victim->setName(victimName);
        Tweet* tweetData = new Tweet(
            victim,
            content
        );
        tweet->setTweet(tweetData);
    }
}

