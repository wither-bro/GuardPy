#include <SFML/Graphics.hpp>
#include <string>

class GuardPyTitle {
private:
    sf::Text titleText;
    sf::Font font;

public:
    GuardPyTitle(const std::string& fontPath) {
        font.loadFromFile(fontPath);

        titleText.setFont(font);
        titleText.setString("GuardPy");
        titleText.setCharacterSize(24);
        titleText.setFillColor(sf::Color::White);

        sf::FloatRect textRect = titleText.getLocalBounds();
        titleText.setOrigin(textRect.width, 0.f);
        titleText.setPosition(780.f, 10.f);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(titleText);
    }
};
