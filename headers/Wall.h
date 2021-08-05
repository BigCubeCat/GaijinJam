#pragma once
#include <box2d/box2d.h>
#include "../headers/GameObject.h"


class Wall : public GameObject{
public:
    Wall(b2World &world, float x, float y, float w, float h);
private:
    b2World *world;
};


