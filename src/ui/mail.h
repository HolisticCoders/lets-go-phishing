#ifndef GUIMAIL_H
#define GUIMAIL_H

#include "raylib.h"
#include "../mail.h"

class GUI_Mail{
    public:
        GUI_Mail(){};
        void update();
        void setMail(Mail* mail) {
            m_mail = mail;
        }
        Rectangle getTitleBounds(){
            const float x = m_x;
            const float y = m_y;
            const float width = m_width;
            const float height = 10;
            return (Rectangle){x, y, width, height};
        }
        Rectangle getContentBounds(){
            const float x = m_x;
            const float y = m_y + 20;
            const float width = m_width;
            const float height = m_height;
            return (Rectangle){x, y, width, height};
        }
    private:
        int m_x = 35;
        int m_y = 60;
        int m_width = 405;
        int m_height = 530;
        Color m_color = LIGHTGRAY;
        Mail* m_mail = nullptr;
};

#endif
