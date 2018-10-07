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
    DrawRectangle(
        avatarBounds().x,
        avatarBounds().y,
        avatarBounds().width,
        avatarBounds().height,
        GRAY
    ); // draw Avatar bounds

    char* name = (char*)m_victim->name().c_str();
    GuiLabel(nameBounds(), name);

    /* char* profession = (char*)m_victim->profession().c_str(); */
    char* profession = "Cook";
    GuiLabel(professionBounds(), profession);

    /* char* maritalStatus = (char*)m_victim->maritalStatus().c_str(); */
    char* maritalStatus = "Married";
    GuiLabel(maritalStatusBounds(), maritalStatus);

    char* children = (char*)std::to_string(m_victim->children()).c_str();
    GuiLabel(childrenBounds(), children);

    /* char *intStr = itoa(a); */
    char* money = (char*)("$ " + std::to_string(m_victim->money())).c_str();
    GuiLabel(moneyBounds(), money);

    // bio field
    char* bio = (char*)m_victim->bio().c_str();
    GuiTextBoxMulti(bioBounds(), bio, 10, false);
}
