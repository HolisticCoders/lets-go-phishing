#include <iostream>

#include "raylib.h"
#include "raygui.h"

#include "mail.h"
#include "board.h"


void GUI_Mail::sendMail(){
    std::cout << "Sending Mail" << std::endl;
    m_board->endTurn();
}

void GUI_Mail::update() {
    // draw title
    char* title = (char*)m_mail->title().c_str();
    GuiLabel(titleBounds(), title);
    // draw content
    char* content = (char*)m_mail->content().c_str();
    GuiTextBoxMulti(contentBounds(), content, 10, false);
    //draw Send button
    if(GuiButton( buttonBounds(), "SEND"))
        sendMail();
}
