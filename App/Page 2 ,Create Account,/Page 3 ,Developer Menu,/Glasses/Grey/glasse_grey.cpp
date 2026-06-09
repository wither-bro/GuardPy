#include <SFML/Graphics.hpp>

class GreyGlass {
private:
    sf::RectangleShape greyFrame;

public:
    GreyGlass(float screenWidth, float screenHeight) {
        greyFrame.setSize(sf::Vector2f(screenWidth, screenHeight));
        greyFrame.setFillColor(sf::Color(128, 128, 128, 150));
        greyFrame.setPosition(0.f, 0.f);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(greyFrame);
    }
};
