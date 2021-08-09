#pragma once
#include "../headers/GameObject.h"
#include <box2d/box2d.h>

class Character : public GameObject {
private:
    float mass;
public:
    Character(
        b2World &world, float x, float y, 
        float w, float h, float weight
    );
    sf::Texture withMask;
    sf::Texture noMasked;
    float speed = 1.0f;
    bool stoped = true;
    float minSpeed = MINIMUM_SPEED;
    float maxSpeed = MAXIMUM_SPEED;
    b2World *world;
    bool animated = true; // TODO delete, when animation be ready
    std::string current_animation;
    Animation animation;
    void Update(float deltaTime);
    void Move(float x, float y);
};