#include <SFML/Graphics.hpp>
#include <string>

class BackButton {
private:
    sf::Text backText;
    sf::Font font;

public:
    BackButton(const std::string& fontPath) {
        font.loadFromFile(fontPath);

        backText.setFont(font);
        backText.setString("< Back");
        backText.setCharacterSize(20);
        backText.setFillColor(sf::Color(128, 128, 128));
        backText.setPosition(720.f, 10.f);
    }

    bool isClicked(sf::RenderWindow& window) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            return backText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        }
        return false;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(backText);
    }
};
