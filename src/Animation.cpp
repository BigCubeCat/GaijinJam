#include "../headers/Animation.h"

void Animation::setTextures(std::vector<sf::Texture> sp) {
    this->frames = sp;
}

void Animation::Tick() {
    this->currentTexture = (this->currentTexture + 1) % this->countTexture;
}

sf::Texture Animation::getTexture() {
    return this->frames[this->currentTexture];
}
