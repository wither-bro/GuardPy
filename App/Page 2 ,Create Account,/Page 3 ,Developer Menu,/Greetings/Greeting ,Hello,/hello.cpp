#include <SFML/Graphics.hpp>
#include <string>

struct UserSession {
    static std::string username;
};
std::string UserSession::username = "User";

class Hello {
private:
    sf::Text greetingText;
    sf::Font font;
    sf::Clock timer;
    bool isVisible = true;
    bool isMoving = false;
    float moveSpeed = 300.f;

public:
    Hello(const std::string& fontPath) {
        font.loadFromFile(fontPath);
        
        greetingText.setFont(font);
        greetingText.setString("Hello " + UserSession::username + "!");
        greetingText.setCharacterSize(60);
        greetingText.setFillColor(sf::Color::White);
        
        sf::FloatRect textRect = greetingText.getLocalBounds();
        greetingText.setOrigin(textRect.width / 2.0f, textRect.height / 2.0f);
        greetingText.setPosition(400.f, 300.f);
    }

    void update(float deltaTime) {
        if (!isVisible) return;

        if (!isMoving && timer.getElapsedTime().asSeconds() >= 4.0f) {
            isMoving = true;
        }

        if (isMoving) {
            greetingText.move(0, -moveSpeed * deltaTime);
            if (greetingText.getPosition().y < -100.f) {
                isVisible = false;
            }
        }
    }

    bool isActive() const {
        return isVisible;
    }

    void draw(sf::RenderWindow& window) {
        if (isVisible) {
            window.draw(greetingText);
        }
    }
};
