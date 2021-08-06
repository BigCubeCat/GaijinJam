#include "../headers/Player.h"
#include <iostream>

using namespace std;

Player::Player(
        b2World &world, int x, int y
    ) : Character(world, x, y, PLAYER_DIAMETR, PLAYER_DIAMETR, 100) {
    this->speed = PLAYER_SPEED;
}


void Player::Update() {
    this->Callback();
    this->Move(this->xSpeed, this->ySpeed);
    Character::Update();
}

void Player::Callback() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) this->ySpeed = -0.5;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) this->ySpeed = 0.5;
    else this->ySpeed = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) this->xSpeed = -0.5;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->xSpeed = 0.5;
    else this->xSpeed = 0;
}