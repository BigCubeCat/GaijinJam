#pragma once
#include "../headers/Character.h"
#include "../headers/PointMap.h"

class Client : public Character {
private:
    float normalize(int);
    float spendedTime;
    float yVector, xVector;
    std::string path;

    sf::SoundBuffer sb[3];
    sf::Sound sound;
    bool isSound = false;
    PointMap *points;
    std::queue<sf::Vector2f> wayToEnd;
public:
    float freeTime;
    float dieTime;
    bool goToShop = false;
    bool atCheckout = false;
    bool masked = false;
    sf::Vector2f currentPoint;
    std::vector<sf::Vector2f> lastPoints;
    Client(b2World &world, float x, float y, float w, float h, float weight,
            std::vector<sf::Vector2f> lastPoint, int symIndex, PointMap &points);
   // Client(const Client &client);
    void ReactToClass(int);
    void Update(float deltaTime);
    void chooseWay();
    bool nearThePoint(sf::Vector2f position, sf::Vector2f point);
};