#include <SFML/Graphics.hpp>
#include "../../../Text Box/Name Box/name.cpp"
#include "../../../Text Box/Password Box/password.cpp"

class ButtonCreate {
private:
    sf::RectangleShape buttonBody;
    sf::Text buttonText;
    sf::Font font;
    bool isActive = false;

public:
    ButtonCreate(const std::string& fontPath, float x, float y) {
        font.loadFromFile(fontPath);

        buttonBody.setSize({150.f, 50.f});
        buttonBody.setOrigin(75.f, 25.f);
        buttonBody.setPosition(x, y);
        
        buttonText.setFont(font);
        buttonText.setString("Create");
        buttonText.setCharacterSize(24);
        
        sf::FloatRect textRect = buttonText.getLocalBounds();
        buttonText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        buttonText.setPosition(x, y - 5.f);
    }

    void update(const NameBox& nameBox, const PasswordBox& passBox) {
        if (!nameBox.getName().empty() && !passBox.getPass().empty()) {
            isActive = true;
            buttonBody.setFillColor(sf::Color(128, 0, 128));
            buttonText.setFillColor(sf::Color::White);
        } else {
            isActive = false;
            buttonBody.setFillColor(sf::Color(60, 0, 60));
            buttonText.setFillColor(sf::Color(150, 150, 150));
        }
    }

    bool isClicked(sf::RenderWindow& window, sf::Event& event) {
        if (!isActive) return false;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
            return buttonBody.getGlobalBounds().contains(mousePos);
        }
        return false;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(buttonBody);
        window.draw(buttonText);
    }
};
