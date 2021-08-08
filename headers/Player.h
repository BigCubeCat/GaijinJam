
#include "../headers/Character.h"


class Player : public Character {
public:
    float xSpeed = 0;
    float ySpeed = 0;
    bool masked;
    
    Player(b2World &world, int x, int y);
    void Update(float deltaTime);
    void Callback();
    void OnCollisionBegin(int);
    void OnCollisionEnd(int);
};