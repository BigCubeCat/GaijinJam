#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

const float SCALE = 30.f; 
const float PLAYER_SPEED = 4.0;
const float PLAYER_DIAMETR = 50.0f;
const float POINT_DISTANCE = 0.9;
const int MINIMUM_POINTS = 4;
const int MAXIMUM_POINTS = 10;

// physics
const float ACCELERATION = 0.1;
const float DEFAULT_DAMPING = 0.9f;
const float DEFAULT_FRICTION = 0.1f;

// Type's id
const int GAME_OBJECT = 0;