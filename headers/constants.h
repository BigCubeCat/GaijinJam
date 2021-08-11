#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

const float SCALE = 120.f; 
const float PLAYER_SPEED = 1.0;
const float PLAYER_DIAMETR = 50.0f;
const float POINT_DISTANCE = 10.0f;
const std::string ALPHABET = "abcdefjhijklmn";
const float PLAYER_MASS = 250.0f;

// AI
const float MINIMUM_FREE_TIME = 1.0f; // in seconds;
const float MAXIMUM_FREE_TIME = 10.0f; // in seconds;
const int ROTATE_PROBABILITY = 10;
const float SPAWNER_TIME = 1.0f;

// Physics
const float ACCELERATION = 1.0f;
const float MINIMUM_SPEED = 1.0f;
const float MAXIMUM_SPEED = 5.0f;
const float DEFAULT_DAMPING = 0.9f;
const float DEFAULT_FRICTION = 0.5;
const float DEFAULT_RESTITUTION = 0.5;
const float BLAST_RADIUS = 150.0f;
const float BLAST_POWER = 100.0f; 

// Type's id
const int GAME_OBJECT = 0;
const int PLAYER_TYPE = 1;
const int CLIENT_TYPE = 2;

// Animations
const float BLINKED_TIME = 0.2f;
const float NO_BLINKED_TIME = 1.0f;
