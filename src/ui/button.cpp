#include <string>

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

using namespace std;


class Button {
    public:
        Button() {
            m_label = "Button";
            m_area = (Rectangle){ 0, 0, 100, 30};
        }
        Button(const string& label) {
            m_label = label;
            m_area = (Rectangle){ 0, 0, 100, 30};
        }
        Button(const Rectangle& area) {
            m_label = "Button";
            m_area = area;
        }
        Button(const string& label, const Rectangle& area) {
            m_label = label;
            m_area = area;
        }
        void update() {
            if (GuiButton(area(), label().c_str())) {
                onClick();
            }
        }
        virtual void onClick() {}
        string label() {
            return m_label;
        }
        Rectangle area() {
            return m_area;
        }
        void setPosition(const Vector2& position) {
            m_area = (Rectangle){ position.x, position.y, m_area.width, m_area.height};
        }
        void setSize(const Vector2& size) {
            m_area = (Rectangle){ m_area.x, m_area.y, size.x, size.y};
        }
        void setArea(const Rectangle& area) {
            m_area = area;
        }
    private:
        Rectangle m_area;
        string m_label;
};
