#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "../headers/Animation.h"

class GameObject {
public:
	float width, height;
	sf::Vector2f position;
	sf::Sprite sprite;
	bool hasCollider = false;
	b2Body *body;
	Animation *animation = nullptr;

	GameObject(sf::Vector2f pos, sf::Sprite sprite, float w=0, float h=0, b2Body *bdy=nullptr);
	void draw(sf::Time delteTime);
};
