#include "../headers/Character.h"
#include "../headers/constants.h"
#include <iostream>

Character::Character(
        b2World &world, float x, float y, 
        float w, float h, float weight
    ) : GameObject(x, y, w, h) {
    this->world = &world;
    this->mass = weight;
    
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
    FixtureDef.density = this->mass;
    FixtureDef.friction = DEFAULT_FRICTION;
    FixtureDef.shape = &Shape;
    FixtureDef.restitution = DEFAULT_RESTITUTION;
    Body->CreateFixture(&FixtureDef);
    Body->SetBullet(true);
    this->SetBody(Body);
    this->animation.currentAnimation = this->masked ? "masked" : "free";
}
/*
Character::Character(const Character &character) : GameObject(character) {
    this->world = character.world;
    this->mass = character.mass;

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
    FixtureDef.density = this->mass;
    FixtureDef.friction = DEFAULT_FRICTION;
    FixtureDef.shape = &Shape;
    FixtureDef.restitution = DEFAULT_RESTITUTION;
    Body->CreateFixture(&FixtureDef);
    Body->SetBullet(true);
    this->SetBody(Body);
    this->animation.currentAnimation = this->masked ? "masked" : "free";

}
*/
void Character::Move(float x, float y) {
    if (this->stoped) this->speed = minSpeed;
    if (speed + ACCELERATION > maxSpeed) this->speed = maxSpeed; else this->speed = speed + ACCELERATION;
    this->body->ApplyForceToCenter(b2Vec2{x * this->speed * this->mass, y * this->speed * this->mass}, true);
    this->stoped = x == 0 && y == 0;
}

void Character::Update(float deltaTime) {
    this->setPosition(this->body->GetPosition().x * SCALE, this->body->GetPosition().y * SCALE);
    this->setTexture(*this->allTextures[this->animation.GetTexture()]);
}

void Character::InitAnimation(std::string path) {
    this->NoMaskA.loadFromFile(path + "na.png");
    this->NoMaskB.loadFromFile(path + "nb.png");
    this->WithMaskA.loadFromFile(path + "ma.png");
    this->WithMaskB.loadFromFile(path + "mb.png");

    this->allTextures[0] = &NoMaskA;
    this->allTextures[1] = &NoMaskB;
    this->allTextures[2] = &WithMaskA;
    this->allTextures[3] = &WithMaskB;

    vector<pair<int, float>> animMasked;
    vector<pair<int, float>> animNotMask;
    pair<int, float> noMaskedA(0, NO_BLINKED_TIME);
    pair<int, float> noMaskedB(1, BLINKED_TIME);
    pair<int, float> maskedA(2, NO_BLINKED_TIME);
    pair<int, float> maskedB(3, BLINKED_TIME);
     
    animMasked.push_back(maskedA);
    animMasked.push_back(maskedB);
    
    animNotMask.push_back(noMaskedA);
    animNotMask.push_back(noMaskedB);

    this->animation.frames = {{"masked", animMasked}, {"free", animNotMask}};
    this->setTexture(*this->allTextures[this->animation.GetTexture()]);
}