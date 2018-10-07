#include <iostream>

#include "raylib.h"
#include "raygui.h"

#include "mail.h"
#include "board.h"


void GUI_Mail::sendMail(){
    m_board.endTurn();
}

void GUI_Mail::update() {
    if (!m_manager.mail()) {
        return;
    }
    // draw title
    char* title = (char*)m_manager.mail()->title().c_str();
    GuiLabel(titleBounds(), title);
    // draw content
    char* content = (char*)m_manager.mail()->content().c_str();
    GuiTextBoxMulti(contentBounds(), content, 10, false);
    //draw Send button
    if(GuiButton( buttonBounds(), "SEND"))
        sendMail();
}
