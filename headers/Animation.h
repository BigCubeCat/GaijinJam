#pragma once
#include <SFML/Graphics.hpp>


class Animation {
public:
    int countSprites;
    int currentSprite;
    sf::Time past_time;
    sf::Time time_to_one_sprite;
    std::vector<sf::Sprite> sprites;
    Animation(std::vector<sf::Sprite>);
    void Tick(sf::Time deltaTime);
    sf::Sprite getSprite();
};
