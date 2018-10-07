#include "raylib.h"
#include "raygui.h"
#include "profile.h"

#include <string>

Rectangle GUI_Profile::avatarBounds(){
    const float x = m_x;
    const float y = m_y;
    const float width = 150;
    return (Rectangle){x, y, width, width};
}

Rectangle GUI_Profile::bioBounds(){
    const float x = m_x;
    const float y = m_y + avatarBounds().height + 10;
    const float width = m_width;
    const float height = m_height - avatarBounds().height - 10;
    return (Rectangle){x, y, width, height};
}

Rectangle GUI_Profile::nameBounds() {
    const float x = m_x + avatarBounds().width + 10;
    const float y = m_y;
    const float width = m_width - avatarBounds().width - 10;
    const float height = 10;
    return (Rectangle){x, y, width, height};
}
Rectangle GUI_Profile::professionBounds() {
    const float x = m_x + avatarBounds().width + 10;
    const float y = m_y + 15;
    const float width = m_width - avatarBounds().width - 10;
    const float height = 10;
    return (Rectangle){x, y, width, height};
}
Rectangle GUI_Profile::maritalStatusBounds(){
    const float x = m_x + avatarBounds().width + 10;
    const float y = m_y + 30;
    const float width = m_width - avatarBounds().width - 10;
    const float height = 10;
    return (Rectangle){x, y, width, height};
}
Rectangle GUI_Profile::childrenBounds(){
    const float x = m_x + avatarBounds().width + 10;
    const float y = m_y + 45;
    const float width = m_width - avatarBounds().width - 10;
    const float height = 10;
    return (Rectangle){x, y, width, height};
}
Rectangle GUI_Profile::moneyBounds(){
    const float x = m_x + avatarBounds().width + 10;
    const float y = m_y + 60;
    const float width = m_width - avatarBounds().width - 10;
    const float height = 10;
    return (Rectangle){x, y, width, height};
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
    GuiLabel(nameBounds(), name);

    char* profession = (char*)m_manager.victim()->profession().c_str();
    GuiLabel(professionBounds(), profession);

    char* maritalStatus = (char*)m_manager.victim()->maritalStatus().c_str();
    GuiLabel(maritalStatusBounds(), maritalStatus);

    char* children = (char*)std::to_string(m_manager.victim()->children()).c_str();
    GuiLabel(childrenBounds(), children);

    char* money = (char*)("$ " + std::to_string(m_manager.victim()->money())).c_str();
    GuiLabel(moneyBounds(), money);

    // bio field
    char* bio = (char*)m_manager.victim()->bio().c_str();
    GuiTextBoxMulti(bioBounds(), bio, 10, false);
}
