#include "../headers/Player.h"
#include <iostream>

Player::Player(
        sf::RenderWindow *window, sf::Clock *clock, b2World *world, int x, int y, sf::Sprite sprite
    ) : Character(window, clock, world, 500, 500, sprite, 400, 400, 100) {
}


void Player::Update(sf::Time deltaTime) {
    this->Callback();
    Character::Move(b2Vec2{this->xSpeed, this->ySpeed});
    Character::Update(deltaTime);
}

void Player::Callback() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) this->ySpeed = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) this->ySpeed = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) this->xSpeed = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->xSpeed = 1;
}