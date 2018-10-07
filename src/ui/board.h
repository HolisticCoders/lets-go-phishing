#ifndef GUI_BOARD_H
#define GUI_BOARD_H

#include <string>

#include "raylib.h"
#include "raygui.h"

#include "../mail.h"
#include "../manager.h"
#include "../player.h"
#include "../resources.h"
#include "../tweet.h"
#include "../victim.h"

//ui includes
#include "tweet.h"
#include "mail.h"
#include "profile.h"

class GUI_Button;

class GUI_Board {
    public:

        // Constructors
        GUI_Board(Player* player);
        ~GUI_Board();

        // Accessors.
        Player* player() {return m_player;}
        Mail* mail() {return m_mail;}
        bool closing() {return m_closing;}

        // Mutators
        void setPlayer(Player* player) {m_player = player;}
        void setMail(Mail* mail) {
            m_mail = mail;
            m_guiMail->setMail(mail);
        }
        void setClosing(const bool& closing) {m_closing = closing;}

        // Member functions
        void update();
        void drawMails();
        void drawTweets();
        void endTurn();

    private:
        Player* m_player;
        Manager* m_manager = nullptr;
        Mail* m_mail = nullptr;
        Tweet* m_tweets[5];
        bool m_closing = false;
        GUI_Button* m_buttons[4];
        GUI_Tweet* m_guiTweets[5];
        GUI_Mail* m_guiMail;
        GUI_Profile* m_guiProfile;
};

#endif
