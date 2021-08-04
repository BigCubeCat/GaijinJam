#include "../headers/LayerSystem.h"

LayerSystem::LayerSystem(std::vector<std::vector<GameObject>> layers) {
    this->allLayers = layers;
}

void LayerSystem::DrawAll(sf::Time time) {
    for (auto layer : this->allLayers) {
        for (auto gameObject : layer) {
            gameObject.draw(time);
        }
    }

}