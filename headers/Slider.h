#pragma once
#include "../headers/GameObject.h"
#include "../headers/Player.h"

class Slider : public GameObject {
private:
    float minX;
    float maxX;
    float middle;
    float scale;
    Player *player;
public:
    Slider(float minX, float maxX, float x, float y, float w, float h, Player &);
    void Update();
};
