#ifndef _SFMLPRIMITIVSDRAWER_HPP_
#define _SFMLPRIMITIVSDRAWER_HPP_

#include <SFML/Graphics.hpp>


class SFMLPrimitivsDrawer {
public:
    SFMLPrimitivsDrawer(sf::RenderWindow &window);
    void drawText(const std::string &text, const sf::Font &font, const sf::Vector2f &position, const sf::Color &color, unsigned int size);
private:
    sf::RenderWindow &_window;
};


#endif // _SFMLPRIMITIVSDRAWER_HPP_
