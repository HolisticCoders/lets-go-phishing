#ifndef GUI_BOARD_H
#define GUI_BOARD_H

#include <string>

#include "raylib.h"
#include "raygui.h"

#include "../manager.h"
#include "../results.h"

//ui includes
#include "tweet.h"
#include "mail.h"
#include "profile.h"

class GUI_Button;

class GUI_Board {
    public:

        // Constructors
        GUI_Board();
        ~GUI_Board();

        // Accessors.
        bool closing() {return m_closing;}

        // Mutators
        void setClosing(const bool& closing) {m_closing = closing;}

        // Member functions
        void update();
        void showResults(Results& results);

    private:
        Manager& m_manager = Manager::getInstance();
        bool m_closing = false;
        Results* m_turnResults = nullptr;
        GUI_Button* m_buttons[4];
        GUI_Tweet* m_guiTweets[5];
        GUI_Mail* m_guiMail;
        GUI_Profile* m_guiProfile;
};

#endif
