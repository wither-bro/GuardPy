#include <SFML/Graphics.hpp>
#include <string>

class ButtonApi {
private:
    sf::RectangleShape button;
    sf::Text text;
    sf::Text arrow;
    sf::Font font;

public:
    ButtonApi(const std::string& fontPath, float x, float y) {
        font.loadFromFile(fontPath);

        button.setSize(sf::Vector2f(200.f, 40.f));
        button.setFillColor(sf::Color(128, 0, 128));
        button.setPosition(x, y);

        text.setFont(font);
        text.setString("API Keys");
        text.setCharacterSize(18);
        text.setFillColor(sf::Color::White);
        text.setPosition(x + 10.f, y + 10.f);

        arrow.setFont(font);
        arrow.setString(">");
        arrow.setCharacterSize(18);
        arrow.setFillColor(sf::Color::White);
        arrow.setPosition(x + 175.f, y + 10.f);
    }

    bool isClicked(sf::RenderWindow& window) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            return button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        }
        return false;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(button);
        window.draw(text);
        window.draw(arrow);
    }
};
