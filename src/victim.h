#ifndef VICTIM_H
#define VICTIM_H

#include <string>

using namespace std;


class Victim {
    public:
        Victim() : 
            m_name{"Person"},
            m_avatarUrl{""},
            m_bio{""},
            m_profession{"Teacher"},
            m_maritalStatus{"Single"},
            m_children{0},
            m_money{0}
        {}
        Victim(
                const string& name, const string& avatarUrl, const string& bio,
                const string& profession, const string& maritalStatus,
                const int& children, const int& money)
            : m_name{name}, m_avatarUrl{avatarUrl}, m_bio{bio},
            m_profession(profession), m_maritalStatus{maritalStatus},
            m_children{children}, m_money{money}
        {}
        string name(){
            return m_name;
        }
        string bio(){
            return m_bio;
        }
        string profession(){
            return m_profession;
        }
        string maritalStatus(){
            return m_maritalStatus;
        }
        int children(){
            return m_children;
        }
        int money(){
            return m_money;
        }
<<<<<<< Updated upstream
        void setName(const string name) {
            m_name = name;
        }
        void setBio(const string bio) {
            m_bio = bio;
        }
        void setProfession(const string profession) {
            m_profession = profession;
        }
        void setMaritalStatus(const string maritalStatus) {
            m_maritalStatus = maritalStatus;
        }
        void setChildren(const int children) {
            m_children = children;
        }
        void setMoney(const int money) {
            m_money = money;
        }
=======
        void setName(string name){
            m_name = name;
        }
>>>>>>> Stashed changes
    private:
        string m_name;
        string m_avatarUrl;
        string m_bio;
        string m_profession;
        string m_maritalStatus;
        int m_children;
        int m_money;
};
#endif
