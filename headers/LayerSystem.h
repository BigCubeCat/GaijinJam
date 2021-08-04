#pragma once
#include <SFML/Graphics.hpp>
#include "../headers/GameObject.h"

class LayerSystem {
public:
    std::vector<std::vector<GameObject>> allLayers;
    LayerSystem(std::vector<std::vector<GameObject>> layers);
    void DrawAll(sf::Time);
};