#include <SFML/Graphics.hpp>
#include <vector>

class CreateAccountPage {
private:
    sf::RectangleShape inputField;
    sf::Text header;
    sf::Text prompt;
    sf::Font font;

public:
    CreateAccountPage(const std::string& fontPath) {
        font.loadFromFile(fontPath);

        header.setFont(font);
        header.setString("Create Account");
        header.setCharacterSize(30);
        header.setFillColor(sf::Color::White);
        header.setPosition(20.f, 20.f);

        prompt.setFont(font);
        prompt.setString("Enter your username:");
        prompt.setCharacterSize(18);
        prompt.setFillColor(sf::Color::White);
        prompt.setPosition(20.f, 80.f);

        inputField.setSize({300.f, 40.f});
        inputField.setFillColor(sf::Color(40, 0, 80));
        inputField.setOutlineThickness(1.f);
        inputField.setOutlineColor(sf::Color::White);
        inputField.setPosition(20.f, 110.f);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(header);
        window.draw(prompt);
        window.draw(inputField);
    }
};
