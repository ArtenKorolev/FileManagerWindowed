#ifndef _RESOURCEMANAGER_HPP_
#define _RESOURCEMANAGER_HPP_

#include <string>
#include <SFML/Graphics.hpp>


class ResourceManager {
public:
    sf::Font loadFont(const std::string &fontFile);
};


#endif // _RESOURCEMANAGER_HPP_
