#include "raylib.h"
#include "raygui.h"
#include "profile.h"
#include "../utils.h"

#include <string>

Rectangle GUI_Profile::avatarBounds(){
    const float x = m_x;
    const float y = m_y;
    const float width = 150;
    return (Rectangle){x, y, width, width};
}

Vector2 GUI_Profile::bioPos(){
    const float x = m_x;
    const float y = m_y + avatarBounds().height + 10;
    return (Vector2){x, y};
}

Vector2 GUI_Profile::namePos() {
    const float x = m_x + avatarBounds().width + 10;
    const float y = m_y;
    return (Vector2){x, y};
}
Vector2 GUI_Profile::professionPos() {
    const float x = m_x + avatarBounds().width + 10;
    const float y = m_y + 15;
    return (Vector2){x, y};
}
Vector2 GUI_Profile::maritalStatusPos(){
    const float x = m_x + avatarBounds().width + 10;
    const float y = m_y + 30;
    return (Vector2){x, y};
}
Vector2 GUI_Profile::childrenPos(){
    const float x = m_x + avatarBounds().width + 10;
    const float y = m_y + 45;
    return (Vector2){x, y};
}
Vector2 GUI_Profile::moneyPos(){
    const float x = m_x + avatarBounds().width + 10;
    const float y = m_y + 60;
    return (Vector2){x, y};
}


void GUI_Profile::update(){
    /* DrawRectangle(m_x, m_y, m_width, m_height, LIGHTGRAY); // draw bounds */
    if (!m_manager.victim()) {
        return;
    }

    DrawRectangle(
        avatarBounds().x,
        avatarBounds().y,
        avatarBounds().width,
        avatarBounds().height,
        GRAY
    ); // draw Avatar bounds

    char* name = (char*)m_manager.victim()->name().c_str();
    /* GuiLabel(nameBounds(), name); */
    DrawTextEx(m_manager.font(), name, namePos(), 13, 1, m_manager.textColor());

    char* profession = (char*)m_manager.victim()->profession().c_str();
    DrawTextEx(m_manager.font(), profession, professionPos(), 13, 1, m_manager.textColor());

    char* maritalStatus = (char*)m_manager.victim()->maritalStatus().c_str();
    DrawTextEx(m_manager.font(), maritalStatus, maritalStatusPos(), 13, 1, m_manager.textColor());

    char* children = (char*)std::to_string(m_manager.victim()->children()).c_str();
    DrawTextEx(m_manager.font(), children, childrenPos(), 13, 1, m_manager.textColor());

    char* money = (char*)("$" + std::to_string(m_manager.victim()->money())).c_str();
    DrawTextEx(m_manager.font(), money, moneyPos(), 13, 1, m_manager.textColor());

    // bio field
    std::string rawContent = m_manager.victim()->bio();

    //convert the string to a char[] of the appropriate size
    char* content = new char[rawContent.length() + 1]; 
    strcpy(content, rawContent.c_str());

    // create a buffer with room for the new line characters
    char* buffer = new char[rawContent.length() + 10];
    // generate a new char[] with \n characters
    char* wrappedContent = word_wrap(buffer, content, 77);

    /* GuiTextBoxMulti(bioPos(), wrappedContent, 10, false); */
    DrawTextEx(m_manager.font(), wrappedContent, bioPos(), 13, 1, m_manager.textColor());

    // delete temporary stuff
    delete [] content;
    delete [] buffer;
}
