#include "../headers/GameObject.h"
#include <box2d/box2d.h>

class Character : public GameObject {
public:
    Character(
        sf::RenderWindow *window, sf::Clock *clock, b2World *world, float x, float y, 
        sf::Sprite sprite, float w, float h, float weight);
    b2World *world;
    bool animated = false; // TODO delete, when animation be ready
    std::string current_animation;
    std::map<std::string, Animation> animations;
    void Update(sf::Time deltaTime); // get time at last call
    void Move(b2Vec2);
};