#include <SFML/Graphics.hpp>

class HumanIcon {
private:
    sf::CircleShape background;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Text logoText;
    sf::Font font;

public:
    HumanIcon(const std::string& imagePath, const std::string& fontPath, float x, float y) {
        background.setRadius(50.f);
        background.setOrigin(50.f, 50.f);
        background.setPosition(x, y);
        background.setFillColor(sf::Color(100, 100, 100));

        if (texture.loadFromFile(imagePath)) {
            sprite.setTexture(texture);
            sf::FloatRect bounds = sprite.getLocalBounds();
            sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
            sprite.setPosition(x, y);
        }

        font.loadFromFile(fontPath);
        logoText.setFont(font);
        logoText.setString("GP");
        logoText.setCharacterSize(20);
        logoText.setFillColor(sf::Color::White);
        
        sf::FloatRect textBounds = logoText.getLocalBounds();
        logoText.setOrigin(textBounds.width / 2.f, textBounds.height / 2.f);
        logoText.setPosition(x, y + 20.f);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(background);
        window.draw(sprite);
        window.draw(logoText);
    }
};
