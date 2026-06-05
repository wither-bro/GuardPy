#include <SFML/Graphics.hpp>
#include <string>

class PasswordBox {
private:
    sf::RectangleShape box;
    sf::Font font;
    sf::Text text;
    std::string input;
    std::string maskedInput;
    std::string placeholder = "Enter your password";
    bool isFocused = false;

public:
    PasswordBox(const std::string& fontPath, float x, float y) {
        font.loadFromFile(fontPath);

        box.setSize({300.f, 40.f});
        box.setPosition(x, y);
        box.setFillColor(sf::Color::Black);
        box.setOutlineThickness(1.f);
        box.setOutlineColor(sf::Color::White);

        text.setFont(font);
        text.setCharacterSize(20);
        text.setPosition(x + 10.f, y + 8.f);
        text.setFillColor(sf::Color(150, 150, 150));
        text.setString(placeholder);
    }

    void handleEvent(sf::Event& event, sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
            isFocused = box.getGlobalBounds().contains(mousePos);
        }

        if (isFocused && event.type == sf::Event::TextEntered) {
            if (event.text.unicode == 8) {
                if (!input.empty()) {
                    input.pop_back();
                    maskedInput.pop_back();
                }
            } else if ((event.text.unicode >= 'a' && event.text.unicode <= 'z') || 
                       (event.text.unicode >= 'A' && event.text.unicode <= 'Z') || 
                       (event.text.unicode >= '0' && event.text.unicode <= '9')) {
                input += static_cast<char>(event.text.unicode);
                maskedInput += '*';
            }

            if (input.empty()) {
                text.setString(placeholder);
                text.setFillColor(sf::Color(150, 150, 150));
            } else {
                text.setString(maskedInput);
                text.setFillColor(sf::Color::White);
            }
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(box);
        window.draw(text);
    }
};
