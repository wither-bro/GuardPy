#include <SFML/Graphics.hpp>
#include <string>
#include <chrono>

class CopyApiKey {
private:
    bool showNotification = false;
    std::chrono::steady_clock::time_point startTime;
    sf::RectangleShape notificationBox;
    sf::Text notificationText;

public:
    CopyApiKey(const sf::Font& font) {
        notificationBox.setSize(sf::Vector2f(300.f, 50.f));
        notificationBox.setFillColor(sf::Color(0, 0, 0, 200));
        notificationBox.setOutlineThickness(1.f);
        notificationBox.setOutlineColor(sf::Color::White);
        
        notificationText.setFont(font);
        notificationText.setCharacterSize(14);
        notificationText.setFillColor(sf::Color::White);
        notificationText.setString("API Key Copied to Clipboard.");
    }

    void CopyToClipboard(const std::string& key) {
        sf::Clipboard::setString(sf::String::fromUtf8(key.begin(), key.end()));
        showNotification = true;
        startTime = std::chrono::steady_clock::now();
    }

    void Update() {
        if (showNotification) {
            auto now = std::chrono::steady_clock::now();
            if (std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count() >= 5) {
                showNotification = false;
            }
        }
    }

    void Draw(sf::RenderWindow& window) {
        if (showNotification) {
            sf::Vector2u winSize = window.getSize();
            float x = (winSize.x - 300.f) / 2.f;
            float y = winSize.y - 100.f;

            notificationBox.setPosition(x, y);
            notificationText.setPosition(x + 50.f, y + 15.f);

            window.draw(notificationBox);
            window.draw(notificationText);
        }
    }
};
