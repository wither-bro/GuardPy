#include <SFML/Graphics.hpp>

class F11Toggle {
private:
    bool isFullscreen = false;
    sf::VideoMode savedMode;

public:
    F11Toggle(sf::VideoMode mode) : savedMode(mode) {}

    void processKey(sf::Event& event, sf::RenderWindow& window) {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11) {
            if (!isFullscreen) {
                window.create(sf::VideoMode::getDesktopMode(), "GuardPy", sf::Style::Fullscreen);
                isFullscreen = true;
            } else {
                window.create(savedMode, "GuardPy", sf::Style::Default);
                isFullscreen = false;
            }
        }
    }
};
