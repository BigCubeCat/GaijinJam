#include "../headers/GameObject.h"
#include <iostream>

GameObject::GameObject(float x, float y, float w, float h) : sf::Sprite() {
    sf::Vector2f pos(x, y);
    this->position = pos;
    this->height = h;
    this->width = w;
}

sf::Vector2f GameObject::GetBodyPosition() {
    return sf::Vector2f{this->body->GetPosition().x * SCALE, this->body->GetPosition().y * SCALE};
}