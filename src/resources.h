#ifndef RESOURCES_H
#define RESOURCES_H

#include <string>

#include <json.hpp>


using namespace std;
using namespace nlohmann;


class Resources {
    public:
        Resources(const string root);
        ~Resources();
        string root() { return m_root; }
        void setRoot(const string root) { m_root = root; }
        void getResource(const char* path, json* data);
        json& categories() { return *m_categories; }
        json& mails() { return *m_mails; }
        json& maritalStatus() { return *m_maritalStatus; }
        json& professions() { return *m_professions; }
        json& tweets() { return *m_tweets; }
        json& victims() { return *m_victims; }
    private:
        string m_root;
        json* m_categories = new json;
        json* m_mails = new json;
        json* m_maritalStatus = new json;
        json* m_professions = new json;
        json* m_tweets = new json;
        json* m_victims = new json;
};


#endif
