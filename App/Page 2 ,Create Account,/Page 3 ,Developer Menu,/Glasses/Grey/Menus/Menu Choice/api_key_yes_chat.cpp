#include <SFML/Graphics.hpp>
#include <string>
#include "../../../../Left Panel/Storage/Glasses/Grey/Other/Buttons/Button ,API Keys,/Menus/Menu Storage/Menu API/ApiKeysLogic.h"
#include "AppNavigator.h"

class ApiKeyYesChat {
private:
    sf::RectangleShape box;
    sf::Text titleText;
    sf::RectangleShape button;
    sf::Text buttonText;
    sf::Font font;
    bool wasClicked = false;

public:
    ApiKeyYesChat(const std::string& fontPath, float x, float y) {
        font.loadFromFile(fontPath);

        box.setSize(sf::Vector2f(300.f, 150.f));
        box.setFillColor(sf::Color(255, 255, 255, 50));
        box.setPosition(x, y);

        titleText.setFont(font);
        titleText.setString("Get API Key with Chat");
        titleText.setCharacterSize(18);
        titleText.setFillColor(sf::Color::White);
        titleText.setPosition(x + 20.f, y + 20.f);

        button.setSize(sf::Vector2f(80.f, 30.f));
        button.setFillColor(sf::Color(128, 0, 128));
        button.setPosition(x + 110.f, y + 90.f);

        buttonText.setFont(font);
        buttonText.setString("Get");
        buttonText.setCharacterSize(16);
        buttonText.setFillColor(sf::Color::White);
        
        sf::FloatRect textRect = buttonText.getLocalBounds();
        buttonText.setOrigin(textRect.width / 2.0f, textRect.height / 2.0f);
        buttonText.setPosition(x + 150.f, y + 105.f);
    }

    void update(sf::RenderWindow& window) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                if (!wasClicked) {
                    ApiKeysLogic::CreateInitialKey(true);
                    AppNavigator::NavigateTo("StoragePanel");
                    wasClicked = true;
                }
            }
        } else {
            wasClicked = false;
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(box);
        window.draw(titleText);
        window.draw(button);
        window.draw(buttonText);
    }
};
