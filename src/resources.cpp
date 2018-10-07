#include <iostream>
#include <string>
#include <fstream>

#include "json.hpp"

#include "resources.h"

using namespace std;
using namespace nlohmann;


Resources::Resources(const string root) : m_root{root} {
    getResource("categories.json", m_categories);
    getResource("mails.json", m_mails);
    getResource("maritalStatus.json", m_maritalStatus);
    getResource("professions.json", m_professions);
    getResource("tweets.json", m_tweets);
    getResource("victims.json", m_victims);
}

// Get a specific resource file content from the
// "resources" folder.
void Resources::getResource(const char* path, json* data) {
    string fullPath = m_root;
    fullPath.append(path);
    cout << "Resource path: " << fullPath << endl;
    ifstream input(fullPath);
    if (!input.good()) {
        input.close();
    }
    input >> *data;
    input.close();
}


Resources::~Resources() {
    delete m_categories;
    delete m_mails;
    delete m_maritalStatus;
    delete m_professions;
    delete m_tweets;
    delete m_victims;
}

