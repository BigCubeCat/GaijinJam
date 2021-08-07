#include "../headers/Client.h"
#include "../headers/constants.h"
#include <iostream>


Client::Client(
    b2World &world, float x, float y, float w, float h, 
    float weight, sf::Vector2f lastPoint, bool masked
) : Character(world, x, y, w, h, weight, CLIENT_TYPE) {
    this->lastPoint = lastPoint;
    this->masked = masked;
    this->chooseWay();
}

void Client::Update(float deltaTime) {
    if (this->goToShop) {
        auto pos = sf::Vector2f{this->body->GetPosition().x * SCALE, this->body->GetPosition().y * SCALE};
        if (this->nearThePoint(this->lastPoint, pos)) {
            std::cout << "Finished\n";
        }
         this->Move(
            normalize(this->lastPoint.x - pos.x),
            normalize(this->lastPoint.y - pos.y)
        );
    } else {
        this->spendedTime += deltaTime;
        if (this->spendedTime > this->freeTime) {
            this->goToShop = true;
        }
        this->Move(this->xVector, this->yVector);

    }
    Character::Update(deltaTime);
}

bool Client::nearThePoint(sf::Vector2f pos, sf::Vector2f point) {
    return (abs(pos.x - point.x) < this->speed) && (abs(pos.y - point.y) < this->speed);
}

void Client::chooseWay() {
}

float Client::normalize(int num) {
    if (num == 0) return 0;
    else if (num < 0) return -1.f;
    return 1.f;
}