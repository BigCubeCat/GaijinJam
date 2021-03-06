#pragma once
#include "../headers/GameObject.h"
#include <box2d/box2d.h>
#include <SFML/Audio.hpp>

class Character : public GameObject {
private:
   float mass;
public:
    Character(b2World &world, float x, float y, float w, float h, float weight);

    sf::Texture NoMaskA;
    sf::Texture NoMaskB;
    sf::Texture WithMaskA;
    sf::Texture WithMaskB;
    sf::Texture *allTextures[8];

    float speed = 1.0f;
    bool stoped = true;
    bool masked = false;
    float minSpeed = MINIMUM_SPEED;
    float maxSpeed = MAXIMUM_SPEED;

    b2World *world;
    Animation animation;
    std::string current_animation;

    void Update(float deltaTime);
    void Move(float x, float y, float deltaTime);
    void InitAnimation(std::string path);
    void SetType(int);
};