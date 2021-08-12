#pragma once
#include "../headers/GameObject.h"
#include "../headers/Player.h"

class Slider : public GameObject {
private:
    float minX;
    float maxX;
    float maxValue;
    float minValue;
    Player *player;
public:
    Slider(float x, float y, float w, float h, Player &);
    void Update();
};
