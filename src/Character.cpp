#include "../headers/Character.h"
#include "../headers/constants.h"
#include <iostream>

Character::Character(
        b2World &world, float x, float y, 
        float w, float h, float weight, int typeIndex
    ) : GameObject(x, y, w, h, typeIndex) {
    this->world = &world;
    
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(x / SCALE, y / SCALE);
    BodyDef.type = b2_dynamicBody;
    b2Body* Body = this->world->CreateBody(&BodyDef);
 
    b2CircleShape Shape;
    Shape.m_p.Set(this->width / SCALE, this->height / SCALE);
    Shape.m_radius = this->width / 2 / SCALE;

    Body->SetFixedRotation(true);
    Body->SetLinearDamping(DEFAULT_DAMPING);

    b2FixtureDef FixtureDef;
    FixtureDef.density = weight;
    FixtureDef.friction = DEFAULT_FRICTION;
    FixtureDef.shape = &Shape;
    Body->CreateFixture(&FixtureDef);
    Body->SetBullet(true);
    this->SetBody(Body);
}

void Character::Move(float x, float y) {
    if (this->stoped) this->speed = minSpeed;
    // setup acceleration
    if (speed + ACCELERATION > maxSpeed) this->speed = maxSpeed; else this->speed = speed + ACCELERATION;
    this->body->SetLinearVelocity(b2Vec2{x * this->speed, y * this->speed});
    this->stoped = x == 0 && y == 0;
}

void Character::Update(float deltaTime) {
    if (this->animated) {
        //this->animation.Tick();
        //this->setTexture(this->animation.getTexture());
    }
    this->setPosition(this->body->GetPosition().x * SCALE, this->body->GetPosition().y * SCALE);
    x = this->body->GetPosition().x * SCALE;
    y = this->body->GetPosition().y * SCALE;
}