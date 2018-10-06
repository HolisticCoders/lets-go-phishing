#ifndef BUTTON_H
#define BUTTON_H

#include <string>

#include "raylib.h"


using namespace std;


class GUI_Button {
    public:
        GUI_Button();
        GUI_Button(const string& label);
        GUI_Button(const string& label, const Rectangle& area);
        void update();
        virtual void onClick();
        string label() {return m_label;}
        Rectangle area() {return m_area;}
        void setPosition(const Vector2& position);
        void setSize(const Vector2& size);
        void setArea(const Rectangle& area) {m_area = area;}
    private:
        string m_label;
        Rectangle m_area;
};

#endif
