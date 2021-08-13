#include "../headers/Player.h"
#include <iostream>

using namespace std;

Player::Player(
        b2World &world, int x, int y, Sensor sensor
    ) : Character(world, x, y, PLAYER_DIAMETR, PLAYER_DIAMETR, PLAYER_MASS),
                                                              sensor(sensor) {
    this->minSpeed = PLAYER_START_SPEED;
    this->maxSpeed = PLAYER_SPEED;
    this->SetType(PLAYER_TYPE);
    this->masked = true;
    this->sensor = sensor;
    this->InitAnimation("../assets/characters/P");
}

void Player::Update(float deltaTime) {
    this->sensor.body->SetTransform(this->body->GetPosition(), 0);
    this->Callback();
    this->Move(this->xSpeed, this->ySpeed);
    this->animation.currentAnimation = this->masked ? "masked" : "free";
    this->animation.Tick(deltaTime);
    for (b2ContactEdge* ce = this->body->GetContactList(); ce; ce = ce->next) {
        this->ReactToClass(ce->other->GetUserData().pointer);
    }
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

void Player::Blast(b2Body* body, b2Vec2 blastDir, float blastPower) {
    blastDir.x *= blastPower;
    blastDir.y *= blastPower;
    body->ApplyLinearImpulseToCenter(blastDir, true);
}

void Player::FindBlastedObjects() {
    for (auto b : this->sensor.DetectedBodies()) {
        if (b == this->body) continue;
        b2Vec2 dir = b->GetPosition() - this->body->GetPosition();
        this->Blast(b, dir, BLAST_POWER);
    }
}

void Player::ReactToClass(int TypeIndex) {
    switch (TypeIndex) {
        case CLIENT_TYPE:
            this->score += PLUS;
            break;
    }
}