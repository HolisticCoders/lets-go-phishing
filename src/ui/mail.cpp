#include <iostream>
#include <string>

#include "raylib.h"
#include "raygui.h"

#include "../utils.h"
#include "mail.h"
#include "../manager.h"

using namespace std;


void GUI_Mail::sendMail(){
    m_manager.endTurn();
}

void GUI_Mail::update() {
    if (!m_manager.mail()) {
        return;
    }
    // draw title
    string rawTitle = m_manager.mail()->title();

    //convert the string to a char[] of the appropriate size
    char* title = new char[rawTitle.length() + 1]; 
    strcpy(title, rawTitle.c_str());
    GuiLabel(titleBounds(), title);

    // draw content
    string rawContent = m_manager.mail()->content();

    //convert the string to a char[] of the appropriate size
    char* content = new char[rawContent.length() + 1]; 
    strcpy(content, rawContent.c_str());
    // create a buffer with room for the new line characters
    char* buffer = new char[rawContent.length() + 10];
    // generate a new char[] with \n characters
    char* wrappedContent = word_wrap(buffer, content, 70);

    DrawRectangleLines(contentBounds().x, contentBounds().y, contentBounds().width, contentBounds().height, BLACK);
    /* DrawText(wrappedContent, contentBounds().x + 10, contentBounds().y + 10, 12, BLACK); */
    Vector2 textPos {contentBounds().x + 10, contentBounds().y + 10};
    DrawTextEx(Manager::getInstance().font(), wrappedContent, textPos, 13, 1, BLACK);
    /* GuiTextBoxMulti(contentBounds(), wrappedContent, 10, false); */

    //draw Send button
    if(GuiButton( buttonBounds(), "SEND"))
        sendMail();
}
