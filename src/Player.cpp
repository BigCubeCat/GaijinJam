#include "../headers/Player.h"
#include <iostream>

using namespace std;

Player::Player(
        b2World &world, int x, int y
    ) : Character(world, x, y, PLAYER_DIAMETR, PLAYER_DIAMETR, 100, PLAYER_TYPE) {
    this->maxSpeed = PLAYER_SPEED;
    this->TypeIndex = PLAYER_TYPE;
    this->body->GetUserData().pointer = this->TypeIndex;
}


void Player::Update(float deltaTime) {
    this->Callback();
    this->Move(this->xSpeed, this->ySpeed);
    Character::Update(deltaTime);
}

void Player::Callback() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) this->ySpeed = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) this->ySpeed = 1;
    else this->ySpeed = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) this->xSpeed = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->xSpeed = 1;
    else this->xSpeed = 0;
}

void Player::OnCollisionBegin(int typeIndex) {
    std::cout << "Enter\n";
}

void Player::OnCollisionEnd(int typeIndex) {
    std::cout << "exit\n";
}