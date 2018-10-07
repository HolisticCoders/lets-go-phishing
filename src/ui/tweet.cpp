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
    cout << m_tweet->author()->name() << " has been clicked" << endl;
    Manager* manager = &Manager::getInstance();
    manager->setVictim(m_tweet->author());
}

bool GUI_Tweet::isClicked(){
    bool clicked = false;
    Vector2 mousePoint = GetMousePosition();

    if (CheckCollisionPointRec(mousePoint, contentBounds())){
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            clicked = true;
        }
    }

    return clicked;
}

void GUI_Tweet::update(){
    DrawRectangle(m_x, m_y, m_width, m_height, m_color);
    if (!m_tweet) {
        return;
    }
    if (m_tweet->author()) {
        char* name = (char*)m_tweet->author()->name().c_str();
        GuiLabel(nameBounds(), name);
    }

    std::string rawContent = m_tweet->content();

    //convert the string to a char[] of the appropriate size
    char* content = new char[rawContent.length() + 1]; 
    strcpy(content, rawContent.c_str());

    // create a buffer with room for the new line characters
    char* buffer = new char[rawContent.length() + 10];
    // generate a new char[] with \n characters
    char* wrappedContent = word_wrap(buffer, content, 55);

    GuiTextBoxMulti(contentBounds(), wrappedContent, 10, false);

    // delete temporary stuff
    delete [] content;
    delete [] buffer;

    if(isClicked()) {
        onClicked();
    }
}
