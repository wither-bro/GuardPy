#include <SFML/Graphics.hpp>
#include "../../Text Box/Password Box/password.cpp"

class ErrorPassword {
private:
    sf::Text errorText;
    sf::Font font;

public:
    ErrorPassword(const std::string& fontPath, float x, float y) {
        font.loadFromFile(fontPath);
        errorText.setFont(font);
        errorText.setCharacterSize(14);
        errorText.setFillColor(sf::Color::Red);
        errorText.setPosition(x, y);
    }

    void draw(sf::RenderWindow& window, const PasswordBox& passwordBox) {
        int errorType = passwordBox.getErrorStatus();
        if (errorType == 1) {
            errorText.setString("Fill this field, please.");
            window.draw(errorText);
        } else if (errorType == 2) {
            errorText.setString("This password already exists.");
            window.draw(errorText);
        }
    }
};
