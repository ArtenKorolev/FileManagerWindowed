#include "SFMLInterface.hpp"


void SFMLInterface::mainLoop() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "File Manager");
    SFMLPrimitivsDrawer drawer(window);
    ResourceManager resourceManager;

    window.setFramerateLimit(60);

    sf::Event event;

    sf::Font font = resourceManager.loadFont("../Assets/Fonts/arialmt.ttf");
    drawer.drawText("Hello, SFML!", font, sf::Vector2f(100, 100), sf::Color::White, 30);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
        }
    }
}
