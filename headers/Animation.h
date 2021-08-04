#pragma once
#include <SFML/Graphics.hpp>


class Animation {
    int countSprites;
    int currentSprite;
    std::vector<sf::Sprite> sprites;
    Animation(std::vector<sf::Sprite>);
};
