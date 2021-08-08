#include "../headers/Wall.h"

Wall::Wall(b2World &world, float x, float y, float w, float h) : GameObject(x, y, w, h) {
    this->x = x;
    this->y = y;
    this-> world = &world;
    b2BodyDef BodyDef;
    BodyDef.type = b2_staticBody;
    BodyDef.position = b2Vec2(x/ SCALE, y/SCALE);
    b2Body* Body = this->world->CreateBody(&BodyDef);

    b2PolygonShape Shape;
    Shape.SetAsBox(w/SCALE, h/SCALE);

    b2FixtureDef FixtureDef;
    FixtureDef.density = 1.0f;
    FixtureDef.friction = 0.1f;
    FixtureDef.shape = &Shape;
    Body->CreateFixture(&FixtureDef);
    this->body = Body;

}