#include "raygui.h"
#include "tweet.h"

void GUI_Tweet::update(){
    DrawRectangle(m_x, m_y, m_width, m_height, m_color);
    if (!m_tweet) {
        return;
    }
    if (m_tweet->author()) {
        char* name = (char*)m_tweet->author()->name().c_str();
        GuiLabel(nameBounds(), name);
    }
    char* text = (char*)m_tweet->content().c_str();
    GuiTextBoxMulti(contentBounds(), text, 10, false);
}
