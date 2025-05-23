#ifndef _SFMLINTERFACE_HPP_
#define _SFMLINTERFACE_HPP_

#include <SFML/Graphics.hpp>
#include "SFMLPrimitivsDrawer.hpp"
#include "Constants.hpp"
#include "ResourceManager.hpp"


class SFMLInterface {
public:
    void mainLoop();
private:
    void _handleEvents(sf::RenderWindow &window);
};


#endif // _SFMLINTERFACE_HPP_
