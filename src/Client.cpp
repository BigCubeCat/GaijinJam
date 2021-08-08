#include "../headers/Client.h" 
#include "../headers/constants.h"
#include <iostream>


Client::Client(
    b2World &world, float x, float y, float w, float h, 
    float weight, sf::Vector2f lastPoint, int symIndex, bool masked
) : Character(world, x, y, w, h, weight) {
    this->lastPoint = lastPoint; 
    this->masked = masked; 
    char sym = 'a'; //ALPHABET[symIndex];
    
    std::string maskedTexture(1, sym);
    std::string noMaskedTexture(1, sym);
    this->NoMask.loadFromFile("assets/characters/aN.png");
    this->WithMask.loadFromFile("assets/characters/" + maskedTexture + "M.png");
    this->chooseWay();
    this->TypeIndex = CLIENT_TYPE;
    std::cout << "TypeIndex " << this->TypeIndex << std::endl;
    this->body->GetUserData().pointer = this->TypeIndex;
    std::cout << "pointer " << this->body->GetUserData().pointer << std::endl;
}

void Client::Update(float deltaTime) {
    if (this->masked) {
        this->setTexture(this->WithMask);
    } else {
        this->setTexture(this->NoMask);
    }
    if (this->goToShop) {
        auto pos = sf::Vector2f{this->body->GetPosition().x * SCALE, this->body->GetPosition().y * SCALE};
        if (this->nearThePoint(this->lastPoint, pos)) {
        }
         this->Move(
            normalize(this->lastPoint.x - pos.x),
            normalize(this->lastPoint.y - pos.y)
        );
    } else {
        this->spendedTime += deltaTime;
        if (this->spendedTime > this->freeTime) {
            this->goToShop = true;
            return;
        }
        if (rand() % 100 <= ROTATE_PROBABILITY) {// меняем курс 
            this->chooseWay();
        }
        this->Move(this->xVector, this->yVector);

    }
    for (b2ContactEdge* ce = this->body->GetContactList(); ce; ce = ce->next) {
        this->ReactToClass(ce->other->GetUserData().pointer);
    }
    Character::Update(deltaTime);
}

bool Client::nearThePoint(sf::Vector2f pos, sf::Vector2f point) {
    return (abs(pos.x - point.x) < this->speed) && (abs(pos.y - point.y) < this->speed);
}

void Client::chooseWay() {
    this->xVector = (float)((rand() - rand()) % 100) / 100; 
    this->yVector = (float)((rand() - rand()) % 100) / 100; 
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
    auto old_x = this->x;
    this->xVector = -this->yVector;
    this->yVector = old_x;
}

float Client::normalize(int num) {
    if (num == 0) return 0;
    else if (num < 0) return -1.f;
    return 1.f;
}