#include "../headers/Player.h"
#include <iostream>

using namespace std;

Player::Player(
        b2World &world, int x, int y, Sensor sensor
    ) : Character(world, x, y, PLAYER_DIAMETR, PLAYER_DIAMETR, PLAYER_MASS),
                                                              sensor(sensor) {
    this->minSpeed = PLAYER_START_SPEED;
    this->setScale(0.6, 0.6);
    this->maxSpeed = PLAYER_SPEED;
    this->SetType(PLAYER_TYPE);
    this->masked = true;
    this->sensor = sensor;
    this->InitAnimation("../assets/characters/P");

    this->sb[0].loadFromFile("../assets/sounds/apch1.wav");
    this->sb[1].loadFromFile("../assets/sounds/apch2.wav");
    this->sb[2].loadFromFile("../assets/sounds/mas1.wav");
    this->sb[3].loadFromFile("../assets/sounds/mas2.wav");
    this->sb[4].loadFromFile("../assets/sounds/mas3.wav");
}

void Player::Update(float deltaTime) {
    this->sensor.body->SetTransform(this->body->GetPosition(), 0);
    this->Callback();
    this->Move(this->xSpeed, this->ySpeed, deltaTime);
    this->animation.currentAnimation = this->masked ? "masked" : "free";
    this->animation.Tick(deltaTime);
    for (b2ContactEdge* ce = this->body->GetContactList(); ce; ce = ce->next) {
        this->ReactToClass(ce->other->GetUserData().pointer);
    }
 Character::Update(deltaTime);
}

void Player::Callback() {
    if (sf::Joystick::isConnected(0)) {
        this->ySpeed = sf::Joystick::getAxisPosition(0, sf::Joystick::Y) / 100;
        this->xSpeed = sf::Joystick::getAxisPosition(0, sf::Joystick::X) / 100;
    }
    else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) this->ySpeed = -1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) this->ySpeed = 1;
        else this->ySpeed = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) this->xSpeed = -1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->xSpeed = 1;
        else this->xSpeed = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Joystick::isButtonPressed(0, 0)) {
        if (this->sound.getStatus() == sf::SoundSource::Stopped) {
            this->sound.setBuffer(this->sb[rand() % 2]);
            this->sound.play();
        }
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
            if (this->sound.getStatus() == sf::SoundSource::Stopped) {
                this->sound.setBuffer(this->sb[rand() % 3 + 2]);
                this->sound.play();
            }
            break;
    }
}