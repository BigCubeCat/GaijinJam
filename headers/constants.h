#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

const float SCALE = 30.f; 

b2Vec2 Gravity(0.f, 9.8f);
b2World World(Gravity);
sf::RenderWindow Window(sf::VideoMode(1900, 1200), "Game", sf::Style::Resize);
sf::Clock Clock;
