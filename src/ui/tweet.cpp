#include "raygui.h"
#include "tweet.h"

void GUI_Tweet::update(){
    DrawRectangle(m_x, m_y, m_width, m_height, m_color);
    GuiLabel(getNameBounds(), "@JongJong");
    char* text = (char*)m_tweet->content().c_str();
    GuiTextBoxMulti(getContentBounds(), text, 10, false);
}
