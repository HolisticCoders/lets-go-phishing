#ifndef GUIPROFILE_H
#define GUIPROFILE_H

#include "raylib.h"
#include "../victim.h"
#include "../manager.h"

class GUI_Profile {
    public:
        GUI_Profile(){};
        void update();

        Rectangle avatarBounds();
        Vector2 namePos();
        Vector2 professionPos();
        Vector2 maritalStatusPos();
        Vector2 childrenPos();
        Vector2 moneyPos();
        Vector2 bioPos();
    private:
        int m_x = 485;
        int m_y = 60;
        int m_width = 405;
        int m_height = 625;
        Manager& m_manager = Manager::getInstance();

};

#endif
