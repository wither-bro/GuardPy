#include <SFML/Graphics.hpp>

class ErrorName {
private:
    sf::Text errorText;
    sf::Font font;

public:
    ErrorName(const std::string& fontPath, float x, float y) {
        font.loadFromFile(fontPath);
        errorText.setFont(font);
        errorText.setCharacterSize(14);
        errorText.setFillColor(sf::Color::Red);
        errorText.setString("Fill this field, please.");
        errorText.setPosition(x, y);
    }

    void draw(sf::RenderWindow& window, bool show) {
        if (show) {
            window.draw(errorText);
        }
    }
};
