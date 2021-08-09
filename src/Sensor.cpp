#include "../headers/Sensor.h"
#include "../headers/constants.h"

Sensor::Sensor(b2World &world, float x, float y, float radius) {
    this->SetRadius(radius);
    this->world = &world;
 
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(x / SCALE, y / SCALE);
    BodyDef.type = b2_dynamicBody;
    this->body = this->world->CreateBody(&BodyDef);
 
    b2CircleShape Shape;
    Shape.m_p.Set(this->radius / SCALE, this->radius / SCALE);
    Shape.m_radius = this->radius / 2 / SCALE;

    this->body->SetFixedRotation(true);

    b2FixtureDef FixtureDef;
    FixtureDef.shape = &Shape;
    FixtureDef.isSensor = true;
    this->body->CreateFixture(&FixtureDef);
    //Body->SetBullet(true);
}

std::vector<b2Body*> Sensor::DetectedBodies() {
    std::vector<b2Body*> allBodies;

    for (b2ContactEdge* ce = this->body->GetContactList(); ce; ce = ce->next) {
        allBodies.push_back(ce->other);
    }

    return allBodies;
}

void Sensor::SetRadius(float radius) {
    this->radius = radius;
}