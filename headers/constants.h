#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#define INF 100000007

const float SCALE = 120.f; 
const float PLAYER_SPEED = 400.0f;
const float PLAYER_START_SPEED = 100.0;
const float PLAYER_DIAMETR = 58.0f;
const float POINT_DISTANCE = 2.0f;
const std::string ALPHABET = "abcdefjhijklmn";
const std::string SOUNDS[10] = {
        "../assets/sounds/bump/oi1.wav",
        "../assets/sounds/bump/oi2.wav",
        "../assets/sounds/bump/oi3.wav",
        "../assets/sounds/bump/oi4.wav",
        "../assets/sounds/bump/oi5.wav",
        "../assets/sounds/bump/oi6.wav",
        "../assets/sounds/bump/oi7.wav",
        "../assets/sounds/bump/oi8.wav",
        "../assets/sounds/bump/oi9.wav",
        "../assets/sounds/bump/oi10.wav",
};
const float PLAYER_MASS = 100.0f;

// Score
const int PLUS = 1;
const int MINUS = 5;
const int SCORE = 100;

// AI
const int MINIMUM_FREE_TIME = 1.0f; // in seconds;
const int MAXIMUM_FREE_TIME = 10.0f; // in seconds;
const float SPAWNER_TIME = 5.0f;
const float MINIMUM_SPAWNER_DELAY = 0.0;
const float SPAWNER_ACCELERATION_DELAY = 1.0f;
const float SPAWNER_ACCELERATION = 1.1f;

// Physics
const float ACCELERATION = 50.0f;
const float MINIMUM_SPEED = 50.0f;
const float MAXIMUM_SPEED = 150.0f;
const float DEFAULT_DAMPING = 10.0;
const float DEFAULT_FRICTION = 0.5;
const float DEFAULT_RESTITUTION = 0.1;
const float BLAST_RADIUS = 40.0f;
const float BLAST_POWER = 100.0f; 

// Type's id
const int GAME_OBJECT = 0;
const int PLAYER_TYPE = 1;
const int CLIENT_TYPE = 2;
const int MASKED_CLIENT = 3;

// Animations
const float BLINKED_TIME = 0.2f;
const float NO_BLINKED_TIME = 1.0f;
const float BOOM_TIME = 0.1;

// Screen's
const int START_SCREEN_FIRST = 0;
const int START_SCREEN_SECOND = 1;
const int LEARN_SCREEN = 2;
const int WIN_SCREEN = 3;
const int LOOSE_SCREEN = 4;
const int GAME_SCREEN = 5;
