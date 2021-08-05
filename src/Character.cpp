#include "../headers/Character.h"

Character::Character(
        sf::RenderWindow *window, sf::Clock *clock, b2World *world, float x, float y, 
        sf::Sprite sprite, float w, float h, float weight
    ) : GameObject(window, clock, x, y, sprite, w, h) {
    this->world = world;
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(x / SCALE, y / SCALE);
    BodyDef.type = b2_dynamicBody;
    b2Body* Body = this->world->CreateBody(&BodyDef);
 
    b2CircleShape Shape;
    Shape.m_p.Set(this->width / SCALE, this->height / SCALE);
    Shape.m_radius = this->width / 2 / SCALE;

    b2FixtureDef FixtureDef;
    FixtureDef.density = 10.0f;
    FixtureDef.friction = 10.0f;
    FixtureDef.shape = &Shape;
    Body->CreateFixture(&FixtureDef);
    this->body = Body;
}

void Character::Move(b2Vec2 vector) {
    this->body->ApplyForceToCenter(vector, true);
}

void Character::Update(sf::Time deltaTime) {
    if (this->animated) {
        //this->animations[this->current_animation].Tick(deltaTime);
        //this->sprite = this->animations[this->current_animation].getSprite();
    }
}