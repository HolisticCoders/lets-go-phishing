#ifndef MANAGER_H
#define MANAGER_H

#include <deque> // deque
#include <string> // string

#include "raylib.h"

#include "mail.h"
#include "player.h"
#include "resources.h"
#include "results.h"
#include "tweet.h"
#include "victim.h"

using namespace std;


class GUI_Board;


class Manager {
    // Singleton implementaion found here:
    // https://stackoverflow.com/questions/1008019/c-singleton-design-pattern#1008289

    public:

        // These ones should not be implemented,
        // to prevent copies to pop here and there.
        Manager(Manager const&) = delete;
        void operator=(Manager const&) = delete;

        // Standard way to get the manager
        // is by calling Manager.getInstance();
        static Manager& getInstance() {
            static Manager instance;
            return instance;
        }

        ~Manager();

        Resources* resources() { return m_resources; }
        string* categories() { return m_categories; }
        deque<Mail*> mails() { return m_mails; }
        string* maritalStatus() { return m_maritalStatus; }
        string* professions() { return m_professions; }
        deque<Tweet*> tweets() { return m_tweets; }
        Victim* victims() { return m_victims; }
        Font font() { return m_font; }
        Color lineColor() { return m_lineColor; }
        Color textColor() { return m_textColor; }
        Color focusColor() { return m_focusColor; }

        int categoryCount();
        int mailCount();
        int maritalStatusCount();
        int professionsCount();
        int tweetCount();
        int victimCount();

        Player* player() { return m_player; }
        Victim* victim() {return m_victim;}
        Mail* mail() { return m_mail; }
        GUI_Board* board() { return m_board; }

        void setPlayer(Player* player) { m_player = player; }
        void setVictim(Victim* victim) {m_victim = victim;}
        void setMail(Mail* mail) { m_mail = mail; }
        void setBoard(GUI_Board* board) { m_board = board; }

        // Game control flow.
        bool isPaused() { return m_isPaused; }
        void pause() { m_isPaused = true; };
        void unpause() { m_isPaused = false; }
        void togglePause() { m_isPaused = m_isPaused ? false: true; }
        void setPause(const bool& paused) { m_isPaused = paused; }
        void drawMails();
        void drawTweets();
        void shuffleMails();
        void shuffleTweets();
        void trashMail(Mail* mail);
        Results spamResults(Mail* mail, Victim* victim);
        void endTurn();

    private:
        Manager();

        bool m_isPaused = false;

        Resources* m_resources = nullptr;
        // All these pointers will be loaded at startup,
        // with an array of elements.
        string* m_categories = nullptr;
        deque<Mail*> m_mails;
        string* m_maritalStatus = nullptr;
        string* m_professions = nullptr;
        deque<Tweet*> m_tweets;
        Victim* m_victims = nullptr;

        // pointers to represent the current state of the board
        Player* m_player = nullptr;
        Victim* m_victim = nullptr;
        Mail* m_mail = nullptr;

        // ui stuff
        Font m_font = LoadFontEx("../resources/Roboto-Regular.ttf", 13, 0, 0);
        Color m_lineColor = (Color){144,171,181,255};
        Color m_textColor = (Color){63,63,63,255};
        Color m_focusColor = (Color){201,239,254,255};
        GUI_Board* m_board = nullptr;

};

#endif
