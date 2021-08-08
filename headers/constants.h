#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

const float SCALE = 30.f; 
const float PLAYER_SPEED = 4.0;
const float PLAYER_DIAMETR = 50.0f;
const float POINT_DISTANCE = 0.9;
const char ALPHABET[3] = {'a', 'b', 'c'};

// AI
const float MINIMUM_FREE_TIME = 1.0f; // in seconds;
const float MAXIMUM_FREE_TIME = 10.0f; // in seconds;
const int ROTATE_PROBABILITY = 1;
const float SPAWNER_TIME = 1.0f;

// Physics
const float ACCELERATION = 0.01;
const float DEFAULT_DAMPING = 0.9f;
const float DEFAULT_FRICTION = 0.1f;

// Type's id
const int GAME_OBJECT = 0;
const int PLAYER_TYPE = 1;
const int CLIENT_TYPE = 2;
