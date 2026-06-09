#include <SFML/Graphics.hpp>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "GuardPy");
    window.setFramerateLimit(60);

    int currentPage = 1;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            switch (currentPage) {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                default:
                    break;
            }
        }

        window.clear(sf::Color(20, 20, 20));

        switch (currentPage) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                break;
        }

        window.display();
    }

    return 0;
}
