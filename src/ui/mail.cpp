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
    Vector2 titlePos {titleBounds().x, titleBounds().y + 10};
    DrawTextEx(m_manager.font(), title, titlePos, 13, 1, m_manager.textColor());

    // draw risk and reward.
    string rawReward = "Reward: $" + to_string(m_manager.mail()->reward());
    char* reward = new char[rawReward.length() + 1]; 
    strcpy(reward, rawReward.c_str());
    Vector2 rewardPos {rewardBounds().x, rewardBounds().y + 10};
    DrawTextEx(m_manager.font(), reward, rewardPos, 13, 1, m_manager.textColor());

    string rawRisk;
    if (m_manager.mail()->risk() < 5) {
        rawRisk = "Risk: Low";
    } else if (m_manager.mail()->risk() < 10) {
        rawRisk = "Risk: Medium";
    } else {
        rawRisk = "Risk: High";
    }
    char* risk = new char[rawRisk.length() + 1]; 
    strcpy(risk, rawRisk.c_str());
    Vector2 riskPos {riskBounds().x, riskBounds().y + 10};
    DrawTextEx(m_manager.font(), risk, riskPos, 13, 1, m_manager.textColor());

    // draw content
    string rawContent = m_manager.mail()->content();

    //convert the string to a char[] of the appropriate size
    char* content = new char[rawContent.length() + 1]; 
    strcpy(content, rawContent.c_str());
    // create a buffer with room for the new line characters
    char* buffer = new char[rawContent.length() + 10];
    // generate a new char[] with \n characters
    char* wrappedContent = word_wrap(buffer, content, 70);

    DrawRectangleLines(contentBounds().x, contentBounds().y, contentBounds().width, contentBounds().height, m_manager.lineColor());
    Vector2 textPos {contentBounds().x + 10, contentBounds().y + 10};
    DrawTextEx(m_manager.font(), wrappedContent, textPos, 13, 1, m_manager.textColor());

    //draw Send button
    if (m_manager.victim()) {
        if(GuiButton( buttonBounds(), "SEND"))
            sendMail();
    }
}
