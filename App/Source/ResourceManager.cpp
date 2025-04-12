#include "ResourceManager.hpp"


sf::Font ResourceManager::loadFont(const std::string &fontFile) {
    sf::Font font;
    
    if (!font.loadFromFile(fontFile)) {
        throw std::runtime_error("Не удалось загрузить шрифт: " + fontFile);
    }

    return font;
}
