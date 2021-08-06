#include "../headers/Character.h"

class Client : public Character {
private:
    float normalize(int);
public:
    bool masked = false;
    std::vector<sf::Vector2f> points;
    sf::Vector2f currentPoint;
    sf::Vector2f lastPoint;
    Client(
        b2World &world, float x, float y, float w, float h, 
        float weight, std::vector<sf::Vector2f>, bool masked=false
    );
    void Update();
    void chooseWay();
    bool nearThePoint(sf::Vector2f position, sf::Vector2f point);
};