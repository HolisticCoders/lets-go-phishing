#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include "raylib.h"

#include "mail.h"
#include "resources.h"
#include "tweet.h"
#include "victim.h"
#include "player.h"

using namespace std;


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
        Mail* mails() { return m_mails; }
        string* maritalStatus() { return m_maritalStatus; }
        string* professions() { return m_professions; }
        Tweet* tweets() { return m_tweets; }
        Victim* victims() { return m_victims; }
        Font font() { return m_font; }

        int categoryCount();
        int mailCount();
        int maritalStatusCount();
        int professionsCount();
        int tweetCount();
        int victimCount();

        Player* player() { return m_player; }
        Victim* victim() {return m_victim;}
        Mail* mail() { return m_mail; }

        void setPlayer(Player* player) { m_player = player; }
        void setVictim(Victim* victim) {m_victim = victim;}
        void setMail(Mail* mail) { m_mail = mail; }

    private:
        Manager();

        Resources* m_resources = nullptr;
        // All these pointers will be loaded at startup,
        // with an array of elements.
        string* m_categories = nullptr;
        Mail* m_mails = nullptr;
        string* m_maritalStatus = nullptr;
        string* m_professions = nullptr;
        Tweet* m_tweets = nullptr;
        Victim* m_victims = nullptr;

        // pointers to represent the current state of the board
        Player* m_player = nullptr;
        Victim* m_victim = nullptr;
        Mail* m_mail = nullptr;
        Font m_font = LoadFontEx("../resources/Roboto-Regular.ttf", 13, 0, 0);
};


#endif
