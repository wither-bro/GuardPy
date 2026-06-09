#include <SFML/Graphics.hpp>
#include <string>

class DisabledButton {
private:
    sf::RectangleShape button;
    sf::Text text;
    sf::Font font;
    bool isEnabled;

public:
    DisabledButton(const std::string& fontPath, float x, float y) : isEnabled(false) {
        font.loadFromFile(fontPath);

        button.setSize(sf::Vector2f(200.f, 40.f));
        button.setFillColor(sf::Color(100, 100, 100)); 
        button.setPosition(x, y);

        text.setFont(font);
        text.setString("API Keys");
        text.setCharacterSize(18);
        text.setFillColor(sf::Color(200, 200, 200));
        text.setPosition(x + 10.f, y + 10.f);
    }

    void updateStatus(bool hasRegistration) {
        isEnabled = hasRegistration;
        if (isEnabled) {
            button.setFillColor(sf::Color(128, 0, 128));
            text.setFillColor(sf::Color::White);
        } else {
            button.setFillColor(sf::Color(100, 100, 100));
            text.setFillColor(sf::Color(200, 200, 200));
        }
    }

    bool isClicked(sf::RenderWindow& window) {
        if (!isEnabled) return false;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            return button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        }
        return false;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(button);
        window.draw(text);
    }
};
