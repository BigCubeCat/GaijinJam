#include "../headers/Character.h"
#include "../headers/Point.h"

class Client : public Character {
public:
    bool masked = false;
    Point currentPoint;
    Point nextPoint;
    std::vector<Point> visitedPoints;
    std::map<Point, std::vector<Point>> possibleWays;
    Client(b2World &world, float x, float y, float w, float h, float weight, bool masked=false);
    void setWay(std::map<Point, std::vector<Point>>, Point);
    void Update();
    void chooseWay();
    static bool nearThePoint(sf::Vector2f position, sf::Vector2f point);
};