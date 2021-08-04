#include "../headers/GameObject.h"
#include "../headers/constants.h"

GameObject::GameObject(sf::Vector2f pos, sf::Sprite sprite, float w=0, float h=0, b2Body *bdy=nullptr) {
    this->position = pos;
    this->height = h;
    this->width = w;
}

void GameObject::draw(sf::Time time) {
    Window.draw(this->sprite);
}