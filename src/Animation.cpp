#include "../headers/Animation.h"

Animation::Animation(std::vector<sf::Sprite> sp) {
    this->sprites = sp;
}

void Animation::Tick(sf::Time deltaTime) {
    this->past_time += deltaTime;
    if (this->time_to_one_sprite <= this->past_time) {// need change sprite
        this->currentSprite++;
        if (this->currentSprite == this->countSprites) this->currentSprite = 0;
    }
}

sf::Sprite Animation::getSprite() {
    return this->sprites[this->currentSprite];
}
