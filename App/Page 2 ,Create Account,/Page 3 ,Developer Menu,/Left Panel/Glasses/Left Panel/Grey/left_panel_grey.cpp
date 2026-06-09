#include <SFML/Graphics.hpp>

class LeftPanelGray {
private:
    sf::RectangleShape panel;

public:
    LeftPanelGray() {
        panel.setSize(sf::Vector2f(200.f, 600.f));
        panel.setFillColor(sf::Color(128, 128, 128, 100));
        panel.setPosition(0.f, 0.f);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(panel);
    }
};
