#include <string>

#include "raylib.h"
#include "raygui.h"

#include "../player.cpp"
#include "button.cpp"


class GUI_Board {
    public:

        // Constructors
        GUI_Board() {
            m_player = nullptr;
        }
        GUI_Board(Player* player) : m_player{player} {}

        // Accessors.
        Player* player() {
            return m_player;
        }
        bool closing() {
            return m_closing;
        }

        // Mutators
        void setPlayer(Player* player) {
            m_player = player;
        }
        void setClosing(const bool& closing) {
            m_closing = closing;
        }

        // Member functions
        void update() {
            if (GuiWindowBox((Rectangle){ 0, 0, 1280, 720 }, "Let's go phishing!")) {
                setClosing(true);
            }
            GuiGroupBox((Rectangle){ 925, 50, 330, 550 }, "Twatter");
            GuiGroupBox((Rectangle){ 475, 50, 425, 645 }, "Profile");
            GuiGroupBox((Rectangle){ 25, 50, 425, 570 }, "Send");
            GuiGroupBox((Rectangle){ 25, 645, 425, 50 }, "Emails");
            GuiGroupBox((Rectangle){ 925, 625, 330, 70 }, "Stats");

            GuiLabel((Rectangle){ 935, 635, 36, 25 }, "Money:");
            GuiLabel((Rectangle){ 935, 655, 71, 25 }, "Wanted level:");

            GuiSliderBar((Rectangle){ 1045, 660, 185, 15 }, m_player->wantedLevel(), 0, 100);

            const char* money = std::to_string(m_player->money()).c_str();
            GuiLabel((Rectangle){ 1045, 635, 161, 25 }, money);

            button01.update();
            button02.update();
            button03.update();
            button04.update();
        }

    private:
        Player* m_player;
        bool m_closing = false;
        GUI_Button button01 = GUI_Button(
            "E-Mail 01",
            (Rectangle){ 35, 655, 93, 30 }
        );
        GUI_Button button02 = GUI_Button(
            "E-Mail 02",
            (Rectangle){ 138, 655, 93, 30 }
        );
        GUI_Button button03 = GUI_Button(
            "E-Mail 03",
            (Rectangle){ 241, 655, 93, 30 }
        );
        GUI_Button button04 = GUI_Button(
            "E-Mail 04",
            (Rectangle){ 344, 655, 93, 30 }
        );
};
