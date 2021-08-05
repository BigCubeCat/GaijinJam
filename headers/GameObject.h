#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "../headers/Animation.h"
#include "../headers/constants.h"

class GameObject {
public:
	sf::RenderWindow *window;
	sf::Clock *clock;
	float width, height;
	sf::Vector2f position;
	sf::Sprite sprite;
	b2Body *body;

	GameObject(sf::RenderWindow *window, sf::Clock *clock, float x, float y, sf::Sprite sprite, float w, float h);
	sf::Sprite getCurrentSprite();
};
