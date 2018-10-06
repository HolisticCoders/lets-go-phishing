#include "raygui.h"
#include "tweet.h"

void GUI_Tweet::update(){
    DrawRectangle(m_x, m_y, m_width, m_height, m_color);
    DrawText("@JongJong", m_x + 10, m_y + 10, 12, BLACK);
    char* text = (char*)m_tweet->content().c_str();
    GuiTextBoxMulti(getBounds(), text, 10, false);
}
