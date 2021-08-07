#pragma once
#include <SFML/Graphics.hpp>


class Animation {
public:
    int countTexture = 0;
    int currentTexture = 0;
    std::vector<sf::Texture> frames;
    void setTextures(std::vector<sf::Texture>);
    void Tick();
    sf::Texture getTexture();
};
