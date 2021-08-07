#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "../headers/Animation.h"
#include "../headers/constants.h"

class GameObject : public sf::Sprite {
public:
	float width, height;
	int TypeIndex = GAME_OBJECT;
	sf::Vector2f position;
	float x,y;
	bool needDestroy = false;
	b2Body *body;

	GameObject(float x, float y, float w, float h);
	sf::Vector2f GetBodyPosition();
	void Update();
	void SetBody(b2Body *body);
	void ReactToClass(int classType);
};
