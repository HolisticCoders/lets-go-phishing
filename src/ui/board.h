#ifndef GUI_BOARD_H
#define GUI_BOARD_H

#include <string>

#include "raylib.h"
#include "raygui.h"

#include "../player.h"
#include "../mail.h"

class GUI_Button;

class GUI_Board {
    public:

        // Constructors
        GUI_Board();
        GUI_Board(Player* player);
        ~GUI_Board();

        // Accessors.
        Player* player() {return m_player;}
        Mail* mail() {return m_mail;}
        bool closing() {return m_closing;}

        // Mutators
        void setPlayer(Player* player) {m_player = player;}
        void setMail(Mail* mail) {m_mail = mail;}
        void setClosing(const bool& closing) {m_closing = closing;}

        // Member functions
        void update();
        void drawMails();

    private:
        Player* m_player;
        Mail* m_mail = nullptr;
        bool m_closing = false;
        GUI_Button* m_buttons[4];
};

#endif
