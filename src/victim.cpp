#include <string>
#include "enums.cpp"

using namespace std;


class Victim {
    public:
        Victim(const string& name, const string& avatarUrl, const string& bio, const Professions& profession, const MaritalStatus& maritalStatus, const int& children, const int& money) {
            m_name = name;
            m_avatarUrl = avatarUrl;
            m_bio = bio;
            m_maritalStatus = maritalStatus;
            m_children = children;
            m_money = money;
        }
    private:
        string m_name;
        string m_avatarUrl;
        string m_bio;
        Professions m_profession;
        MaritalStatus m_maritalStatus;
        unsigned int m_children;
        int m_money;
};
