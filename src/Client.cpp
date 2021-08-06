#include "../headers/Client.h"
#include "../headers/constants.h"
#include <iostream>


Client::Client(
    b2World &world, float x, float y, float w, float h, 
    float weight, std::vector<sf::Vector2f> points, bool masked
) : Character(world, x, y, w, h, weight) {
    this->masked = masked;
    this->points = points;
    this->chooseWay();
}

void Client::Update() {
    auto pos = sf::Vector2f{this->body->GetPosition().x * SCALE, this->body->GetPosition().y * SCALE};
    if (this->nearThePoint(this->currentPoint, pos)) {
        this->chooseWay();
    }
    //this->currentPoint = sf::Vector2f{this->body->GetPosition().x * SCALE, this->body->GetPosition().y * SCALE};
     this->Move(
        normalize(this->currentPoint.x - pos.x),
        normalize(this->currentPoint.y - pos.y)
    );
    Character::Update();
}

bool Client::nearThePoint(sf::Vector2f pos, sf::Vector2f point) {
    return (abs(pos.x - point.x) < this->speed) && (abs(pos.y - point.y) < this->speed);
}

void Client::chooseWay() {
    if (this->points.size() == 0) {
        auto pos = sf::Vector2f{this->body->GetPosition().x * SCALE, this->body->GetPosition().y * SCALE};
        if (this->nearThePoint(this->lastPoint, pos)) {
            this->needDestroy = true;
        }
        this->currentPoint = this->lastPoint;
    } else {
        int val = std::rand() % this->points.size();
        this->currentPoint = this->points.at(val);
        this->points.erase(this->points.begin() + val);
    }
}

float Client::normalize(int num) {
    if (num == 0) return 0;
    else if (num < 0) return -1.f;
    return 1.f;
}