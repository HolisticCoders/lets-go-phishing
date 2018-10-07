#ifndef GUITWEET_H
#define GUITWEET_H

#include "raylib.h"
#include "../tweet.h"
#include "../manager.h"

class GUI_Tweet {
    public:
        GUI_Tweet(const int& index) : m_index{index} {};
        void update();
        void onClicked();
        bool isClicked();
        bool isHovered();

        int height() { return m_height; }
        Tweet* tweet() { return m_manager.tweets()[m_index]; }

        void setX(int x){ m_x = x; }
        void setY(int y){ m_y = y; }
        void setWidth(int width){ m_width = width; }
        void setHeight(int height){ m_height = height; }

        Rectangle nameBounds(){
            const float x = m_x + 10;
            const float y = m_y + 10;
            const float width = m_width - 20;
            const float height = 10;
            return (Rectangle){x, y, width, height};
        }
        Rectangle contentBounds(){
            const float x = m_x + 10;
            const float y = m_y + 30;
            const float width = m_width - 20;
            const float height = m_height - 40;
            return (Rectangle){x, y, width, height};
        }

    private:
        int m_x = 0;
        int m_y = 0;
        int m_width = 310;
        int m_height = (550 - 10 * (5 + 1))/5; 
        Color m_color = LIGHTGRAY;
        int m_index;
        Manager& m_manager = Manager::getInstance();
};

#endif
