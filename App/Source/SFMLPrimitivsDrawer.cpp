#include "SFMLPrimitivsDrawer.hpp"


SFMLPrimitivsDrawer::SFMLPrimitivsDrawer(sf::RenderWindow &window)
    : _window(window)
{}

void SFMLPrimitivsDrawer::drawText(const std::string &text, const sf::Font &font, const sf::Vector2f &position, const sf::Color &color, unsigned int size) {
    sf::Text textObject;
    textObject.setFont(font);
    textObject.setString(text);
    textObject.setPosition(position);
    textObject.setFillColor(color);
    textObject.setCharacterSize(size);
    _window.draw(textObject);
}
