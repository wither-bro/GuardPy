#include <SFML/Graphics.hpp>

class StoragePanel {
private:
    sf::RectangleShape greyFrame;
    bool visible;

public:
    StoragePanel() : visible(false) {
        greyFrame.setSize(sf::Vector2f(600.f, 400.f));
        greyFrame.setFillColor(sf::Color(128, 128, 128, 180));
        greyFrame.setPosition(100.f, 100.f);
    }

    void setVisible(bool status) {
        visible = status;
    }

    bool isVisible() const {
        return visible;
    }

    void draw(sf::RenderWindow& window) {
        if (visible) {
            window.draw(greyFrame);
        }
    }
};
