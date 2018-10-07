#include "mail.h"
#include "raylib.h"
#include "raygui.h"
#include <iostream>

void GUI_Mail::sendMail(){
    std::cout << "Sending Mail" << std::endl;
}

void GUI_Mail::update() {
    // draw title
    char* title = (char*)m_mail->title().c_str();
    GuiLabel(getTitleBounds(), title);
    // draw content
    char* content = (char*)m_mail->content().c_str();
    GuiTextBoxMulti(getContentBounds(), content, 10, false);
    //draw Send button
    if(GuiButton( buttonBounds(), "SEND"))
        sendMail();
}
