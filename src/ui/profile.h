#ifndef GUIPROFILE_H
#define GUIPROFILE_H

#include "../victim.h"

class GUI_Profile {
    public:
        GUI_Profile(){};
        void update();

        void setVictim(Victim* victim) {
            m_victim = victim;
        }

        void avatarBounds();
        void nameBounds();
        void professionBounds();
        void maritalStatusBounds();
        void childrenBounds();
        void moneyBounds();
        void bioBounds();
    private:
        int m_x = 485;
        int m_y = 60;
        int m_width = 405;
        int m_height = 625;
        Victim* m_victim = nullptr;
};

#endif
