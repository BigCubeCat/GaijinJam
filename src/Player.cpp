#include "../headers/Player.h"
#include <iostream>

using namespace std;

Player::Player(
        b2World &world, int x, int y, Sensor sensor
        ) : Character(world, x, y, PLAYER_DIAMETR, PLAYER_DIAMETR, PLAYER_MASS),
                                                              sensor(sensor) {
    this->maxSpeed = PLAYER_SPEED;
    this->TypeIndex = PLAYER_TYPE;
    this->body->GetUserData().pointer = this->TypeIndex;
    this->masked = true;
    this->withMask.loadFromFile("assets/characters/playerM.png");
    this->noMasked.loadFromFile("assets/characters/playerW.png");
    this->sensor = sensor;
}


void Player::Update(float deltaTime) {
    this->sensor.body->SetTransform(this->body->GetPosition(), 0);
    if (this->masked) {
        this->setTexture(this->withMask);
    } else {
        this->setTexture(this->noMasked);
    }
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        this->FindBlastedObjects();
    }
}

void Player::OnCollisionBegin(int typeIndex) {
    std::cout << "Enter\n";
}

void Player::OnCollisionEnd(int typeIndex) {
    std::cout << "exit\n";
}

void Player::Blast(b2Body* body, b2Vec2 blastDir, float blastPower) {
    std::cout << blastDir.x << " " << blastDir.y << std::endl;
    blastDir.x *= blastPower;
    blastDir.y *= blastPower;
      body->ApplyLinearImpulseToCenter(blastDir, true);
}

void Player::FindBlastedObjects() {
    int a = 0;
    for (auto b : this->sensor.DetectedBodies()) {
        if (b == this->body) continue;
        a++;
        b2Vec2 dir = this->body->GetPosition() - b->GetPosition();
        this->Blast(b, dir, BLAST_POWER);
    }
    std::cout << "b = " << a << std::endl;
}