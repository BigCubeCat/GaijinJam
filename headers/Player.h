#include "../headers/Character.h"


class Player : public Character {
public:
    float xSpeed = 0;
    float ySpeed = 0;
    
    Player(sf::RenderWindow *window, sf::Clock *clock, b2World *world, int x, int y, sf::Sprite s);
    void Update(sf::Time deltaTime);
    void Callback();
};