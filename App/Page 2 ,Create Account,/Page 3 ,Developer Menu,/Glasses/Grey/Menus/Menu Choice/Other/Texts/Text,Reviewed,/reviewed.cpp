#include <SFML/Graphics.hpp>
#include <string>

class ReviewedText {
private:
    sf::Text text;
    sf::Font font;

public:
    ReviewedText(const std::string& fontPath) {
        font.loadFromFile(fontPath);

        text.setFont(font);
        text.setString("You've reviewed everything");
        text.setCharacterSize(16);
        text.setFillColor(sf::Color::White);

        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.width / 2.0f, textRect.height / 2.0f);
        text.setPosition(400.f, 570.f);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(text);
    }
};
