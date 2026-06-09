#include <SFML/Graphics.hpp>

class EnterHandler {
public:
    void handleEvent(sf::Event& event, bool& isGoPressed) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Enter) {
                isGoPressed = true;
            }
        }
    }
};
