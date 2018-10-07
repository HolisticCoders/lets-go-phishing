#include "raylib.h"
#include "raygui.h"
#include "tweet.h"
#include "../utils.h"
#include "../manager.h"

#include <iostream>
#include <string>
#include <vector>


using namespace std;

void GUI_Tweet::onClicked(){
    Manager* manager = &m_manager;
    manager->setVictim(tweet()->author());
}

bool GUI_Tweet::isClicked(){
    bool clicked = false;
    Vector2 mousePoint = GetMousePosition();

    const float x = m_x;
    const float y = m_y;
    const float width = m_width;
    const float height = m_height; 

    if (CheckCollisionPointRec(mousePoint, (Rectangle){x, y, width, height})){
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            clicked = true;
        }
    }
    return clicked;
}

bool GUI_Tweet::isHovered(){
    bool hovered = false;
    Vector2 mousePoint = GetMousePosition();

    const float x = m_x;
    const float y = m_y;
    const float width = m_width;
    const float height = m_height; 

    if (CheckCollisionPointRec(mousePoint, (Rectangle){x, y, width, height})){
        hovered = true;
    }
    return hovered;
}

void GUI_Tweet::update(){
    if (isHovered())
        DrawRectangle(m_x, m_y, m_width, m_height, m_manager.focusColor());
    DrawRectangleLines(m_x, m_y, m_width, m_height, m_manager.lineColor());
    if (!tweet()) {
        return;
    }
    if (tweet()->author()) {
        char* name = (char*)("@"+tweet()->author()->name()).c_str();
        Vector2 namePos {nameBounds().x, nameBounds().y};
        DrawTextEx(m_manager.font(), name, namePos, 13, 1, m_manager.textColor());
    }

    std::string rawContent = tweet()->content();

    //convert the string to a char[] of the appropriate size
    char* content = new char[rawContent.length() + 1]; 
    strcpy(content, rawContent.c_str());

    // create a buffer with room for the new line characters
    char* buffer = new char[rawContent.length() + 10];
    // generate a new char[] with \n characters
    char* wrappedContent = word_wrap(buffer, content, 51);

    Vector2 contentPos {contentBounds().x, contentBounds().y};
    DrawTextEx(m_manager.font(), wrappedContent, contentPos, 13, 1, m_manager.textColor());

    // delete temporary stuff
    delete [] content;
    delete [] buffer;

    if(isClicked()) {
        onClicked();
    }
}
