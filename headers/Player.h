#pragma once
#include <SFML/Audio.hpp>
#include "../headers/Character.h"
#include "../headers/Sensor.h"

class Player : public Character {
public:
    Sensor sensor;
    int score = 0;
    float xSpeed = 0;
    float ySpeed = 0;
    bool masked;
    
    sf::SoundBuffer sb[12];
    
    sf::Sound sound;
    
    Player(b2World &world, int x, int y, Sensor sensor);
    void Update(float deltaTime);
    void Callback();
    void Blast(b2Body*, b2Vec2, float);
    void FindBlastedObjects();
    void ReactToClass(int);
};