#include <SFML/Graphics.hpp>
#include <string>

class NameBox {
private:
    sf::RectangleShape box;
    sf::Font font;
    sf::Text text;
    std::string input;

public:
    NameBox(const std::string& fontPath, float x, float y) {
        font.loadFromFile(fontPath);

        box.setSize({300.f, 40.f});
        box.setPosition(x, y);
        box.setFillColor(sf::Color(40, 0, 80));
        box.setOutlineThickness(1.f);
        box.setOutlineColor(sf::Color::White);

        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);
        text.setPosition(x + 10.f, y + 8.f);
    }

    void handleInput(sf::Event& event) {
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == 8) {
                if (!input.empty()) input.pop_back();
            } else if (event.text.unicode < 128) {
                input += static_cast<char>(event.text.unicode);
            }
            text.setString(input);
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(box);
        window.draw(text);
    }
};
