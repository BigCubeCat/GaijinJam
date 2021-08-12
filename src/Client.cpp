#include "../headers/Client.h" 
#include "../headers/constants.h"
#include <iostream>


Client::Client(
    b2World &world, float x, float y, float w, float h, 
    float weight, sf::Vector2f lastPoint, int symIndex, bool masked
) : Character(world, x, y, w, h, weight) {
    this->masked = false;
    //this->animation.currentAnimation = this->masked ? "free" : "masked";
    this->lastPoint = lastPoint;
    this->path = "../assets/characters/";
    this->path.push_back(ALPHABET[0]);
    this->TypeIndex = CLIENT_TYPE;
    this->body->GetUserData().pointer = this->TypeIndex;
    this->chooseWay();
    this->InitAnimation(path);
    //this->setTexture(*this->allTextures[this->animation.GetTexture()]);
}
/*
Client::Client(const Client &client) : Character(client) {
    this->masked = false;
    //this->animation.currentAnimation = this->masked ? "free" : "masked";
    this->lastPoint = lastPoint;
    this->path = client.path;
    this->TypeIndex = client.TypeIndex;
    this->body->GetUserData().pointer = client.TypeIndex;
    this->WithMaskA = client.WithMaskA;
    this->WithMaskB = client.WithMaskB;
    this->NoMaskA = client.NoMaskA;
    this->NoMaskB = client.NoMaskB;
    for (int i = 0; i < 4; i++) 
        this->allTextures[i] = client.allTextures[i];
    this->chooseWay();
    this->InitAnimation(client.path);
 }
 */
void Client::Update(float deltaTime) {
    this->Move(this->xVector, this->yVector);
    if (this->goToShop) {
        auto pos = sf::Vector2f{this->body->GetPosition().x * SCALE, this->body->GetPosition().y * SCALE};
        if (this->nearThePoint(this->lastPoint, pos)) {
            this->needDestroy = true;
        }
        this->xVector = normalize(this->lastPoint.x - pos.x);
        this->yVector = normalize(this->lastPoint.y - pos.y);
    } else {
        this->spendedTime += deltaTime;
        if (this->spendedTime > this->freeTime) {
            this->goToShop = true;
            return;
        }
        if (rand() % 100 <= ROTATE_PROBABILITY) {// меняем курс 
            this->chooseWay();
        }
    }
    for (b2ContactEdge* ce = this->body->GetContactList(); ce; ce = ce->next) {
        this->ReactToClass(ce->other->GetUserData().pointer);
    }
    this->animation.currentAnimation = this->masked ? "masked" : "free";
    this->animation.Tick(deltaTime);
    Character::Update(deltaTime);
}

bool Client::nearThePoint(sf::Vector2f pos, sf::Vector2f point) {
    return (abs(pos.x - point.x) < this->speed) && (abs(pos.y - point.y) < this->speed);
}

void Client::chooseWay() {
    this->xVector = (float)(rand() % 21 - 10) / 10;
    this->yVector = (float)(rand() % 21 - 10) / 10;
}

void Client::ReactToClass(int typeIndex) {
    switch (typeIndex) {
        case PLAYER_TYPE:
            this->masked = true;
            break;
        case GAME_OBJECT:
            this->rotateLeft();
            break;
    }
}

void Client::rotateLeft() {
    int old_x = this->x;
    this->xVector = -this->yVector;
    this->yVector = old_x;
}

float Client::normalize(int num) {
    if (num == 0) return 0;
    else if (num < 0) return -1.f;
    return 1.f;
}