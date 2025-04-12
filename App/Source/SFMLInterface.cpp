#include "SFMLInterface.hpp"


void SFMLInterface::mainLoop() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "File Manager");
    SFMLPrimitivsDrawer drawer(window);
    ResourceManager resourceManager;

    sf::Font font = resourceManager.loadFont("../Assets/Fonts/arialmt.ttf");

    while (window.isOpen()) {
        drawer.drawText("Hello, SFML!", font, sf::Vector2f(100, 100), sf::Color::White, 30);
        window.display();
        _handleEvents(window);    
    }
}

void SFMLInterface::_handleEvents(sf::RenderWindow &window) {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            break;
        }
    }
}
