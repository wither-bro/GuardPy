#include <SFML/Graphics.hpp>

class ButtonGo {
private:
    sf::RectangleShape buttonBody;
    sf::Font font;
    sf::Text buttonText;

public:
    ButtonGo(const std::string& fontPath, float x, float y) {
        font.loadFromFile(fontPath);

        buttonBody.setSize({150.f, 50.f});
        buttonBody.setOrigin(75.f, 25.f);
        buttonBody.setPosition(x, y);
        buttonBody.setFillColor(sf::Color(128, 0, 128));
        buttonBody.setOutlineThickness(2.f);
        buttonBody.setOutlineColor(sf::Color(0, 0, 0, 100));

        buttonText.setFont(font);
        buttonText.setString("Go!");
        buttonText.setCharacterSize(24);
        buttonText.setFillColor(sf::Color::White);

        sf::FloatRect textRect = buttonText.getLocalBounds();
        buttonText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        buttonText.setPosition(x, y - 5.f);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(buttonBody);
        window.draw(buttonText);
    }
};
