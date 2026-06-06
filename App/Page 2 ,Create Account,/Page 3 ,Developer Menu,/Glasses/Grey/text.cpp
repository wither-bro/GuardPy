#include <SFML/Graphics.hpp>
#include <string>

class Text {
private:
    sf::Text messageText;
    sf::Font font;

public:
    Text(const std::string& fontPath) {
        font.loadFromFile(fontPath);

        messageText.setFont(font);
        messageText.setString("Do you want to start registering your first API key?\nThen start registering right now!");
        messageText.setCharacterSize(20);
        messageText.setFillColor(sf::Color::White);

        sf::FloatRect textRect = messageText.getLocalBounds();
        messageText.setOrigin(textRect.width / 2.0f, textRect.height / 2.0f);
        messageText.setPosition(400.f, 300.f);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(messageText);
    }
};
