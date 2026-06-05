#include <SFML/Graphics.hpp>
#include <string>

class NameBox {
private:
    sf::RectangleShape box;
    sf::RectangleShape errorBorder;
    sf::Font font;
    sf::Text text;
    std::string input;
    std::string placeholder = "Enter your username";
    bool isFocused = false;
    bool hasError = false;

public:
    NameBox(const std::string& fontPath, float x, float y) {
        font.loadFromFile(fontPath);

        box.setSize({300.f, 40.f});
        box.setPosition(x, y);
        box.setFillColor(sf::Color::Black);
        box.setOutlineThickness(1.f);
        box.setOutlineColor(sf::Color::White);

        errorBorder.setSize({302.f, 42.f});
        errorBorder.setPosition(x - 1.f, y - 1.f);
        errorBorder.setFillColor(sf::Color::Transparent);
        errorBorder.setOutlineThickness(2.f);
        errorBorder.setOutlineColor(sf::Color::Red);

        text.setFont(font);
        text.setCharacterSize(20);
        text.setPosition(x + 10.f, y + 8.f);
        text.setFillColor(sf::Color(150, 150, 150));
        text.setString(placeholder);
    }

    void validate() {
        hasError = input.empty();
    }

    void handleEvent(sf::Event& event, sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
            isFocused = box.getGlobalBounds().contains(mousePos);
        }

        if (isFocused && event.type == sf::Event::TextEntered) {
            if (event.text.unicode == 8) {
                if (!input.empty()) input.pop_back();
            } else if (event.text.unicode >= 32 && event.text.unicode < 127) {
                input += static_cast<char>(event.text.unicode);
            }

            if (input.empty()) {
                text.setString(placeholder);
                text.setFillColor(sf::Color(150, 150, 150));
            } else {
                text.setString(input);
                text.setFillColor(sf::Color::White);
            }
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(box);
        if (hasError) {
            window.draw(errorBorder);
        }
        window.draw(text);
    }

    std::string getName() const {
        return input;
    }

    bool getErrorStatus() const {
        return hasError;
    }
};
