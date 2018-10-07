#ifndef GUIMAIL_H
#define GUIMAIL_H

#include "raylib.h"
#include "../manager.h"

class GUI_Board;


class GUI_Mail{
    public:
        GUI_Mail(GUI_Board& board) : m_board{board} {};
        void update();
        void sendMail();

        Rectangle titleBounds(){
            const float x = m_x;
            const float y = m_y;
            const float width = m_width;
            const float height = 25;
            return (Rectangle){x, y, width, height};
        }
        Rectangle contentBounds(){
            const float x = m_x;
            const float y = m_y + 35;
            const float width = m_width;
            const float height = m_height;
            return (Rectangle){x, y, width, height};
        }
        Rectangle buttonBounds(){
            const float width = 50;
            const float height = 25;
            const float x = m_width - 15;
            const float y = m_y;
            return (Rectangle){x, y, width, height};
        }

    private:
        int m_x = 35;
        int m_y = 60;
        int m_width = 405;
        int m_height = 515;
        Color m_color = LIGHTGRAY;
        GUI_Board& m_board;
        Manager& m_manager = Manager::getInstance();
};

#endif
