#include "../headers/Client.h"
#include "../headers/constants.h"


Client::Client(
    b2World &world, float x, float y, float w, float h, 
    float weight, bool masked=false
) : Character(world, x, y, w, h, weight) {
    this->masked = masked;
}

void Client::setWay(std::map<Point, std::vector<Point>> way, Point point) {
    this->possibleWays = way;
    this->currentPoint = point;
}

void Client::Update() {
    if (this->nearThePoint(this->currentPoint.position, this->nextPoint.position)) {
        this->chooseWay();
    }
    this->Move(
        this->body->GetPosition().x - this->nextPoint.position.x, 
        this->body->GetPosition().y - this->nextPoint.position.y
    );
    Character::Update();
}

bool Client::nearThePoint(sf::Vector2f pos, sf::Vector2f point) {
    return (abs(pos.x - point.x) < POINT_DISTANCE) && (abs(pos.y - point.y) < POINT_DISTANCE);
}

void Client::chooseWay() {
    this->visitedPoints.push_back(this->currentPoint);
    std::vector<Point> possiblePoints;
    for (auto point : this->possibleWays[this->currentPoint]) {
        if (std::find(this->visitedPoints.begin(), this->visitedPoints.end(), point) != this->visitedPoints.end()) 
            possiblePoints.push_back(point);
    }
    int index = std::rand() % possiblePoints.size();
    this->currentPoint = this->nextPoint;
    this->nextPoint = possiblePoints[index];
}