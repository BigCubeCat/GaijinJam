#include "../headers/Client.h" 
#include "../headers/constants.h"
#include "../headers/Helper.h"
#include <iostream>

Client::Client(
    b2World &world, float x, float y, float w, float h, 
    float weight, std::vector<sf::Vector2f> lastPoint, int symIndex, PointMap &points
) : Character(world, x, y, w, h, weight) {
    if (!this->sb[0].loadFromFile(SOUNDS[symIndex % 10])) {
        std::cout << SOUNDS[symIndex % 4] << std::endl;
    }
    this->points = &points;
    std::cout << this->points->points[0][0] << std::endl;
    this->sb[1].loadFromFile("../assets/sounds/mas1.wav");
    this->sb[2].loadFromFile("../assets/sounds/mas1.wav");
    this->sound.setVolume(50.0f);

    this->masked = false;
    this->lastPoints = lastPoint;
    this->path = "../assets/characters/";
    this->path.push_back(ALPHABET[symIndex]);
    this->SetType(CLIENT_TYPE);
    this->chooseWay();
    this->InitAnimation(path);
}

void Client::Update(float deltaTime) {
    for (b2ContactEdge* ce = this->body->GetContactList(); ce; ce = ce->next) {
        this->ReactToClass(ce->other->GetUserData().pointer);
    }
    this->animation.Tick(deltaTime);
    Character::Update(deltaTime);
    this->animation.currentAnimation = this->masked ? "masked" : "free";
    if (this->atCheckout) {
        if (this->sound.getStatus() == sf::SoundSource::Stopped) {
            this->sound.setBuffer(this->sb[rand() % 2 + 1]);
            this->sound.play();
        }
        this->animation.currentAnimation = "die";
        this->spendedTime += deltaTime;
        if (this->spendedTime >= this->dieTime) {
            this->needDestroy = true;
           return;
        }
        return;
    }
    this->Move(this->xVector, this->yVector, deltaTime);
    if (this->goToShop) {
        // path finding
        auto pos = sf::Vector2f{this->body->GetPosition().x * SCALE, this->body->GetPosition().y * SCALE};
        this->points->Search(sf::Vector2i{(int)pos.x, (int)pos.y});
        if (this->nearThePoint(this->currentPoint, pos)) {
            if (!this->wayToEnd.size()) {
                this->xVector = 0.0f;
                this->yVector = 0.0f;
                this->atCheckout = true;
            } else {
                this->currentPoint = this->wayToEnd.front();
                this->wayToEnd.pop();
            }
        }
        this->xVector = normalize(this->currentPoint.x - pos.x);
        this->yVector = normalize(this->currentPoint.y - pos.y);
    } else {
        this->spendedTime += deltaTime;
        if (this->spendedTime >= this->freeTime) {
            this->spendedTime = 0.0f;
            auto pos = sf::Vector2f{this->body->GetPosition().x * SCALE, this->body->GetPosition().y * SCALE};
            this->goToShop = true;
            this->currentPoint = this->points->nearestPoint(pos);
            this->wayToEnd = this->points->Search(sf::Vector2i{
                    (int)this->currentPoint.x, (int)this->currentPoint.y});
        }
    }
}

bool Client::nearThePoint(sf::Vector2f pos, sf::Vector2f point) {
    return (abs(pos.x - point.x) < POINT_DISTANCE) && (abs(pos.y - point.y) < POINT_DISTANCE);
}

void Client::chooseWay() {
    int a = rand();
    float m = (a % 2 == 1) ? 1.0 : -1.0; 
    float n = rand() % 21 - 10;
    if (a / 100 % 10 < 5) {
        this->xVector = m; this->yVector = n;
    } else {
        this->xVector = n; this->yVector = m;
    }
}

void Client::ReactToClass(int typeIndex) {
    switch (typeIndex) {
        case PLAYER_TYPE:
            if (this->sound.getStatus() == sf::SoundSource::Status::Stopped && !this->isSound) {
                this->sound.setBuffer(this->sb[0]);
                this->sound.play();
                this->isSound = true;
            }
            this->masked = true;
            this->SetType(MASKED_CLIENT);
            break;
            case GAME_OBJECT:
                this->chooseWay();
                break;
    }
}

float Client::normalize(int num) {
    if (num == 0) return 0;
    else if (num < 0) return -1.f;
    return 1.f;
}
