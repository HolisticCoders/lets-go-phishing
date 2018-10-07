#ifndef MANAGER_H
#define MANAGER_H

#include <string>

#include "mail.h"
#include "resources.h"
#include "tweet.h"
#include "victim.h"

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

        int categoryCount();
        int mailCount();
        int maritalStatusCount();
        int professionsCount();
        int tweetCount();
        int victimCount();

        void setVictim(Victim* victim) {m_victim = victim;}
        Victim* victim() {return m_victim;}

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
        Victim* m_victim = nullptr;
};


#endif
