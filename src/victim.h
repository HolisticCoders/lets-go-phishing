#ifndef VICTIM_H
#define VICTIM_H

#include <string>
#include "enums.h"

using namespace std;


class Victim {
    public:
        Victim() : 
            m_name{"Person"},
            m_avatarUrl{""},
            m_bio{""},
            m_profession{Teacher},
            m_maritalStatus{Single},
            m_children{0},
            m_money{0}
        {}
        Victim(
                const string& name, const string& avatarUrl, const string& bio,
                const Professions& profession, const MaritalStatus& maritalStatus,
                const int& children, const int& money)
            : m_name{name}, m_avatarUrl{avatarUrl}, m_bio{bio},
            m_profession(profession), m_maritalStatus{maritalStatus},
            m_children{children}, m_money{money}
        {}
    private:
        string m_name;
        string m_avatarUrl;
        string m_bio;
        Professions m_profession;
        MaritalStatus m_maritalStatus;
        int m_children;
        int m_money;
};
#endif
