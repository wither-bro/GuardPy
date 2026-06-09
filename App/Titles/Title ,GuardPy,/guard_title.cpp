#include <SFML/Graphics.hpp>
#include <string>

class GuardTitle {
private:
    sf::Font font;
    sf::Text text;

public:
    GuardTitle(const std::string& fontPath, unsigned int size) {
        if (font.loadFromFile(fontPath)) {
            text.setFont(font);
            text.setString("GuardPy");
            text.setCharacterSize(size);
            text.setFillColor(sf::Color::White);
            text.setPosition(20.0f, 10.0f);
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(text);
    }
};
