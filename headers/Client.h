#include "../headers/Character.h"

class Client : public Character {
private:
    float normalize(int);
    float spendedTime = 0.0f;
    float freeTime;
    float yVector, xVector;
    float changeWayProbability;
    void rotateLeft();
    sf::Texture NoMask;
    sf::Texture WithMask;
public:
    bool goToShop = false;
    bool masked = false;
    //sf::Vector2f currentPoint;
    sf::Vector2f lastPoint;
    Client(
        b2World &world, float x, float y, float w, float h, 
        float weight, sf::Vector2f lastPoint, bool masked
    );
    void ReactToClass(int);
    void Update(float deltaTime);
    void chooseWay();
    bool nearThePoint(sf::Vector2f position, sf::Vector2f point);
};