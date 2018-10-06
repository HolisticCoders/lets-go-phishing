#include "mail.h"
#include "raylib.h"
#include "raygui.h"


void GUI_Mail::update() {
    char* title = (char*)m_mail->title().c_str();
    GuiLabel(getTitleBounds(), title);
    char* content = (char*)m_mail->content().c_str();
    GuiTextBoxMulti(getContentBounds(), content, 10, false);
}
