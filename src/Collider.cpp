#include "../headers/Collider.h"
#include "../headers/constants.h"

 
void CreateBox(int x, int y) {
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(x / SCALE, y / SCALE);
    BodyDef.type = b2_dynamicBody;
    b2Body* Body = World.CreateBody(&BodyDef);
 
    b2PolygonShape Shape;
    Shape.SetAsBox((16.f / 2) / SCALE, (16.f / 2) / SCALE);
    b2FixtureDef FixtureDef;
    FixtureDef.density = 10.0f;
    FixtureDef.friction = 10.0f;
    FixtureDef.shape = &Shape;
    Body->CreateFixture(&FixtureDef);
}