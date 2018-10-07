#include <iostream>
#include <map>

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
    m_mails = new Mail[m_resources->mails().size()];
    m_maritalStatus = new string[m_resources->maritalStatus().size()];
    m_professions = new string[m_resources->professions().size()];
    m_tweets = new Tweet[m_resources->tweets().size()];
    m_victims = new Victim[m_resources->victims().size()];

    // Get track of the victims name to associate them
    // to tweets.
    map<string, Victim*> victimNames;

    for (int i = 0; i < m_resources->professions().size(); i++) {
        cout << "Creating Profession " << m_resources->professions()[i] << endl;
        m_professions[i] = m_resources->professions()[i];
    }
    for (int i = 0; i < m_resources->maritalStatus().size(); i++) {
        cout << "Creating MaritalStatus " << m_resources->maritalStatus()[i] << endl;
        m_maritalStatus[i] = m_resources->maritalStatus()[i];
    }
    for (int i = 0; i < m_resources->categories().size(); i++) {
        cout << "Creating Category " << m_resources->categories()[i] << endl;
        m_categories[i] = m_resources->categories()[i];
    }
    for (int i = 0; i < m_resources->mails().size(); i++) {
        cout << "Creating Mail " << m_resources->mails()[i] << endl;
        json data = m_resources->mails()[i];
        m_mails[i].setTitle(data["title"]);
        m_mails[i].setContent(data["content"]);
        m_mails[i].setCategory(data["category"]);
    }
    for (int i = 0; i < m_resources->victims().size(); i++) {
        cout << "Creating Victim " << m_resources->victims()[i] << endl;
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
        cout << "Creating Tweet " << m_resources->tweets()[i] << endl;
        json data = m_resources->tweets()[i];
        m_tweets[i].setAuthor(victimNames[data["author"]]);
        m_tweets[i].setContent(data["content"]);
    }
}

Manager::~Manager() {
    delete m_resources;
    delete [] m_categories;
    delete [] m_mails;
    delete [] m_maritalStatus;
    delete [] m_professions;
    delete [] m_tweets;
    delete [] m_victims;
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
