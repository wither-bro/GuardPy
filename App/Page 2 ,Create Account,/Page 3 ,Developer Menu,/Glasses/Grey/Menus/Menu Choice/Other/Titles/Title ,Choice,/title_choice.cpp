#include <SFML/Graphics.hpp>
#include <string>

class TitleChoice {
private:
    sf::Text titleText;
    sf::Font font;

public:
    TitleChoice(const std::string& fontPath) {
        font.loadFromFile(fontPath);

        titleText.setFont(font);
        titleText.setString("API Choice");
        titleText.setCharacterSize(30);
        titleText.setFillColor(sf::Color::White);
        titleText.setStyle(sf::Text::Bold);

        sf::FloatRect textRect = titleText.getLocalBounds();
        titleText.setOrigin(textRect.width / 2.0f, 0.f);
        titleText.setPosition(400.f, 20.f);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(titleText);
    }
};
