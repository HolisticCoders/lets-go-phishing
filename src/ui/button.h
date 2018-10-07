#ifndef BUTTON_H
#define BUTTON_H

#include <string>

#include "raylib.h"

#include "../manager.h"


using namespace std;


class Mail;


class GUI_Button {
    public:
        GUI_Button();
        GUI_Button(const string& label);
        GUI_Button(const string& label, const Rectangle& area);
        GUI_Button(const string& label, const Rectangle& area, const int& mailIndex);
        void update();
        virtual void onClick();
        string label() {return m_label;}
        Rectangle area() {return m_area;}
        int mailIndex() { return m_mailIndex; }
        Mail* mail();
        void setPosition(const Vector2& position);
        void setSize(const Vector2& size);
        void setArea(const Rectangle& area) {m_area = area;}
    private:
        string m_label;
        Rectangle m_area;
        int m_mailIndex;
        Manager& m_manager = Manager::getInstance();
};

#endif
