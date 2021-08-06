
#include "../headers/Character.h"


class Player : public Character {
public:
    float xSpeed = 0;
    float ySpeed = 0;
    
    Player(b2World &world, int x, int y);
    void Update();
    void Callback();
};