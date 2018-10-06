#ifndef BUTTON_H
#define BUTTON_H

#include <string>

#include "raylib.h"
#include "board.h"


using namespace std;


class Mail;
class GUI_Board;


class GUI_Button {
    public:
        GUI_Button();
        GUI_Button(const string& label);
        GUI_Button(const string& label, const Rectangle& area);
        ~GUI_Button();
        void update();
        virtual void onClick();
        string label() {return m_label;}
        Rectangle area() {return m_area;}
        Mail* mail() {return m_mail;}
        GUI_Board* board() {return m_board;}
        void setPosition(const Vector2& position);
        void setSize(const Vector2& size);
        void setArea(const Rectangle& area) {m_area = area;}
        void setMail(Mail* mail);
        void setBoard(GUI_Board& board) {m_board = &board;}
    private:
        string m_label;
        Rectangle m_area;
        Mail* m_mail = nullptr;
        GUI_Board* m_board = nullptr;
};

#endif
