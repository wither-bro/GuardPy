#include <SFML/Graphics.hpp>
#include <string>

class ButtonGo {
private:
    sf::RectangleShape buttonRect;
    sf::Text buttonText;
    sf::Font font;

public:
    ButtonGo(const std::string& fontPath) {
        font.loadFromFile(fontPath);

        buttonRect.setSize(sf::Vector2f(120.f, 50.f));
        buttonRect.setFillColor(sf::Color(128, 0, 128));
        buttonRect.setOrigin(60.f, 25.f);
        buttonRect.setPosition(400.f, 300.f);

        buttonText.setFont(font);
        buttonText.setString("Go!");
        buttonText.setCharacterSize(20);
        buttonText.setFillColor(sf::Color::White);

        sf::FloatRect textRect = buttonText.getLocalBounds();
        buttonText.setOrigin(textRect.width / 2.0f, textRect.height / 2.0f);
        buttonText.setPosition(400.f, 300.f);
    }

    bool isClicked(sf::RenderWindow& window) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            return buttonRect.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        }
        return false;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(buttonRect);
        window.draw(buttonText);
    }
};
