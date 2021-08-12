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
    
    auto *boom0 = new sf::Texture();
    auto *boom1 = new sf::Texture();
    auto *boom2 = new sf::Texture();
    auto *boom3 = new sf::Texture();
    boom0->loadFromFile("../assets/boom/0.png");
    boom1->loadFromFile("../assets/boom/1.png");
    boom2->loadFromFile("../assets/boom/2.png");
    boom3->loadFromFile("../assets/boom/3.png");

    this->allTextures[0] = &NoMaskA;
    this->allTextures[1] = &NoMaskB;
    this->allTextures[2] = &WithMaskA;
    this->allTextures[3] = &WithMaskB;
    this->allTextures[4] = boom0;
    this->allTextures[5] = boom1;
    this->allTextures[6] = boom2;
    this->allTextures[7] = boom3;

    vector<pair<int, float>> animMasked;
    vector<pair<int, float>> animNotMask;
    vector<pair<int, float>> animBoom;
    
    pair<int, float> noMaskedA(0, NO_BLINKED_TIME);
    pair<int, float> noMaskedB(1, BLINKED_TIME);
    pair<int, float> maskedA(2, NO_BLINKED_TIME);
    pair<int, float> maskedB(3, BLINKED_TIME);
    pair<int, float> bom0(4, BOOM_TIME);
    pair<int, float> bom1(5, BOOM_TIME);
    pair<int, float> bom2(6, BOOM_TIME);
    pair<int, float> bom3(7, BOOM_TIME);
     
    animMasked.push_back(maskedA);
    animMasked.push_back(maskedB);
    animNotMask.push_back(noMaskedA);
    animNotMask.push_back(noMaskedB);
    animBoom.push_back(bom0);
    animBoom.push_back(bom1);
    animBoom.push_back(bom2);
    animBoom.push_back(bom3);

    this->animation.frames = {{"masked", animMasked}, {"free", animNotMask}, {"die", animBoom}};
    this->setTexture(*this->allTextures[this->animation.GetTexture()]);
}