#ifndef MAIL_H
#define MAIL_H

#include <string>

using namespace std;


class Mail {
    public:

        Mail() : m_title{""}, m_content{""}, m_category{"Phishing"}, m_risk{0}, m_reward{0} {};
        Mail(const string& title, const string& content, const string& category, const int& risk, const int& reward)
            : m_title{title}, m_content{content}, m_category{category}, m_risk{risk}, m_reward{reward}
        {}

        // Accessors
        string title() {return m_title;}
        string content() {return m_content;}
        string category() {return m_category;}
        int risk() { return m_risk; }
        int reward() { return m_reward; }

        // Mutators
        void setTitle(const string& title) {m_title = title;}
        void setContent(const string& content) {m_content = content;}
        void setCategory(const string& category) {m_category = category;}
        void setRisk(const int& risk) { m_risk = risk; }
        void setReward(const int& reward) { m_reward = reward; }

    private:

        string m_title;
        string m_content;
        string m_category;
        int m_risk;
        int m_reward;
};

#endif
