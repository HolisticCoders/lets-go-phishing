#include <iostream>
#include <string>

#include "raylib.h"
#include "raygui.h"

#include "button.h"

using namespace std;


GUI_Button::GUI_Button() {
    m_label = "Button";
    m_area = (Rectangle){ 0, 0, 100, 30};
}

GUI_Button::GUI_Button(const string& label) : m_label{label} {
    m_area = (Rectangle){ 0, 0, 100, 30 };
}

GUI_Button::GUI_Button(const string& label, const Rectangle& area)
    : m_label{label}, m_area{area}
{}


void GUI_Button::update() {
    if (GuiButton(area(), label().c_str())) {
        onClick();
    }
}

void GUI_Button::onClick() {
    if (!m_board) {
        cout << "No board to set attached e-mail to." << endl;
        return;
    }
    if (!m_mail) {
        cout << "No attached e-mail to set on board." << endl;
        return;
    }
    cout << "Displaying E-Mail " << endl;
    m_board->setMail(m_mail);
}

void GUI_Button::setPosition(const Vector2& position) {
    m_area = (Rectangle){ position.x, position.y, m_area.width, m_area.height};
}

void GUI_Button::setSize(const Vector2& size) {
    m_area = (Rectangle){ m_area.x, m_area.y, size.x, size.y};
}

void GUI_Button::setMail(Mail* mail) {
    // Delete the previous mail pointer.
    m_mail = mail;
}

