#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

class Sensor {
private:
    b2World *world;

public:
    b2Body *body;
    float radius = 0;
    Sensor(b2World &world, float x, float y, float radius);
    std::vector<b2Body*> DetectedBodies();
    void SetRadius(float radius);
};