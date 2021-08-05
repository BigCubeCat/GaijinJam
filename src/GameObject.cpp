#include "../headers/GameObject.h"
#include <iostream>

GameObject::GameObject(sf::RenderWindow *window, sf::Clock *clock, float x, float y, sf::Sprite sprite, float w, float h) {
    sf::Vector2f pos(x, y);
    this->position = pos;
    this->height = h;
    this->width = w;
    this->window = window;
    this->clock = clock;
}

sf::Sprite GameObject::getCurrentSprite() {
    auto pos = this->body->GetPosition();
    std::cout << pos.x << " " << pos.y << std::endl;
    std::cout << this->width << " " << this->height << std::endl;
    this->sprite.setPosition(pos.x * SCALE, pos.y * SCALE);
    return this->sprite;
}