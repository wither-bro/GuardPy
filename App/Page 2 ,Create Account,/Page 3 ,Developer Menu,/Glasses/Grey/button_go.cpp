#include <SFML/Graphics.hpp>
#include <string>

class ButtonGo {
private:
    sf::RectangleShape buttonRect;
    sf::Text buttonText;
    sf::Font font;
    bool active;

public:
    ButtonGo(const std::string& fontPath) : active(false) {
        font.loadFromFile(fontPath);

        buttonRect.setSize(sf::Vector2f(200.f, 60.f));
        buttonRect.setFillColor(sf::Color(128, 0, 128));
        buttonRect.setOrigin(100.f, 30.f);
        buttonRect.setPosition(400.f, 400.f);

        buttonText.setFont(font);
        buttonText.setString("Go!");
        buttonText.setCharacterSize(28);
        buttonText.setFillColor(sf::Color::White);

        sf::FloatRect textRect = buttonText.getLocalBounds();
        buttonText.setOrigin(textRect.width / 2.0f, textRect.height / 2.0f);
        buttonText.setPosition(400.f, 400.f);
    }

    bool isClicked(sf::RenderWindow& window) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (buttonRect.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                active = true;
                return true;
            }
        }
        return false;
    }

    bool isOpenMenus() const {
        return active;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(buttonRect);
        window.draw(buttonText);
    }
};
