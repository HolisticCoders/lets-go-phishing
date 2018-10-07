#include <algorithm> // shuffle
#include <iostream> // cout
#include <map> // map
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

#include "json.hpp"

#include "mail.h"
#include "manager.h"
#include "resources.h"
#include "tweet.h"
#include "victim.h"

using namespace std;
using namespace nlohmann;


Manager::Manager() {
    m_resources = new Resources("../resources/");
    m_categories = new string[m_resources->categories().size()];
    m_maritalStatus = new string[m_resources->maritalStatus().size()];
    m_professions = new string[m_resources->professions().size()];
    m_victims = new Victim[m_resources->victims().size()];

    // Get track of the victims name to associate them
    // to tweets.
    map<string, Victim*> victimNames;

    for (int i = 0; i < m_resources->professions().size(); i++) {
        m_professions[i] = m_resources->professions()[i];
    }
    for (int i = 0; i < m_resources->maritalStatus().size(); i++) {
        m_maritalStatus[i] = m_resources->maritalStatus()[i];
    }
    for (int i = 0; i < m_resources->categories().size(); i++) {
        m_categories[i] = m_resources->categories()[i];
    }
    for (int i = 0; i < m_resources->mails().size(); i++) {
        json data = m_resources->mails()[i];
        Mail* mail = new Mail(data["title"], data["content"], data["category"]);
        m_mails.push_back(mail);
    }
    for (int i = 0; i < m_resources->victims().size(); i++) {
        json data = m_resources->victims()[i];
        m_victims[i].setName(data["name"]);
        m_victims[i].setBio(data["bio"]);
        m_victims[i].setProfession(data["profession"]);
        m_victims[i].setMaritalStatus(data["maritalStatus"]);
        m_victims[i].setChildren(data["children"]);
        m_victims[i].setMoney(data["money"]);
        victimNames[data["name"]] = &m_victims[i];
    }
    for (int i = 0; i < m_resources->tweets().size(); i++) {
        json data = m_resources->tweets()[i];
        Tweet* tweet = new Tweet(
            victimNames[data["author"]],
            data["content"]
        );
        m_tweets.push_back(tweet);
    }
}

Manager::~Manager() {
    delete m_resources;
    delete [] m_categories;
    delete [] m_maritalStatus;
    delete [] m_professions;
    delete [] m_victims;

    for (Mail* mail: m_mails) {
        delete mail;
    }
    for (Tweet* tweet: m_tweets) {
        delete tweet;
    }
}


int Manager::categoryCount() {
    return m_resources->categories().size();
}
int Manager::mailCount() {
    return m_resources->mails().size();
}
int Manager::maritalStatusCount() {
    return m_resources->maritalStatus().size();
}
int Manager::professionsCount() {
    return m_resources->professions().size();
}
int Manager::tweetCount() {
    return m_resources->tweets().size();
}
int Manager::victimCount() {
    return m_resources->victims().size();
}

void Manager::endTurn() {
    trashMail(m_mail);
    drawTweets();
}

void Manager::trashMail(Mail* mail) {
    auto it = find(m_mails.begin(), m_mails.end(), mail);
    int index = distance(m_mails.begin(), it);
    cout << "Index of mail to trash: " << index << endl;
    deque<Mail*> tmpMails;

    // Fill the front of the queue, then grab the fifth (index 4)
    // mail and put it at the trashed mail index.
    for (int i = 0; i < index; i++) {
        tmpMails.push_back(m_mails[i]);
        cout << "Adding Top: " << m_mails[i]->title() << endl;
    }
    tmpMails.push_back(m_mails[4]);
    cout << "Adding Next: " << m_mails[4]->title() << endl;

    // Now fill the remaining of the queue and push
    // the trashed mail back.
    for (int i = index + 1; i < m_mails.size(); i++) {
        if (i == 4) {
            i = 5;
        }
        tmpMails.push_back(m_mails[i]);
        cout << "Adding Remainder: " << m_mails[i]->title() << endl;
    }
    tmpMails.push_back(m_mails[index]);
    cout << "Adding Trashed: " << m_mails[index]->title() << endl;

    m_mails.swap(tmpMails);
}
void Manager::drawMails() {}
void Manager::drawTweets() {
    // Create a new deque to discard the five front tweets
    // into.
    deque<Tweet*> tmpTweets;
    for (int i = m_tweets.size() - 1; i >= m_tweets.size() - 5; i--) {
        tmpTweets.push_back(m_tweets[i]);
    }
    for (int i = 0; i < m_tweets.size() - 5; i++) {
        tmpTweets.push_front(m_tweets[i]);
    }
    m_tweets.swap(tmpTweets);
}
void Manager::shuffleMails() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(m_mails.begin(), m_mails.end(), default_random_engine(seed));
}
void Manager::shuffleTweets() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(m_tweets.begin(), m_tweets.end(), default_random_engine(seed));
}

