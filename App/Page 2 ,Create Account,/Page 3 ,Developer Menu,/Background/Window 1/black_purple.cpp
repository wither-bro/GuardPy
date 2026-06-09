#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

class BlackPurpleBackground {
private:
    struct Spark {
        sf::Vector2f position;
        float velocity;
        float opacity;
    };

    std::vector<Spark> sparks;
    sf::VertexArray gradient;

public:
    BlackPurpleBackground(int width, int height) {
        gradient.setPrimitiveType(sf::Quads);
        gradient.resize(4);
        gradient[0].position = {0, 0}; gradient[0].color = sf::Color(20, 0, 40);
        gradient[1].position = {float(width), 0}; gradient[1].color = sf::Color(40, 0, 80);
        gradient[2].position = {float(width), float(height)}; gradient[2].color = sf::Color(10, 0, 20);
        gradient[3].position = {0, float(height)}; gradient[3].color = sf::Color(0, 0, 10);

        for(int i = 0; i < 50; ++i) {
            sparks.push_back({{float(rand() % width), float(rand() % height)}, 
                              float(rand() % 100) / 50.0f, 255.0f});
        }
    }

    void update() {
        for(auto& s : sparks) {
            s.position.y -= s.velocity;
            if(s.position.y < 0) s.position.y = 800;
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(gradient);
        for(auto& s : sparks) {
            sf::CircleShape circle(2.0f);
            circle.setPosition(s.position);
            circle.setFillColor(sf::Color(100, 200, 255, 150));
            window.draw(circle);
        }
    }
};