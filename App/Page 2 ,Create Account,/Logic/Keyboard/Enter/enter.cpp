#include <SFML/Graphics.hpp>
#include "../../Buttons/Button ,Create/button_create.cpp"

class EnterKeyHandler {
public:
    static void handle(sf::Event& event, ButtonCreate& button) {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
            button.press();
        }
    }
};
