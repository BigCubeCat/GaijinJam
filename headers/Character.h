#pragma once
#include "../headers/GameObject.h"
#include <box2d/box2d.h>

class Character : public GameObject {
public:
    Character(
        b2World &world, float x, float y, 
        float w, float h, float weight
    );
    float speed = 1.0f;
    bool stoped = true;
    float minSpeed = 1.0f;
    float maxSpeed = 10.0f;
    b2World *world;
    bool animated = true; // TODO delete, when animation be ready
    std::string current_animation;
    Animation animation;
    void Update();
    void Move(float x, float y);
};