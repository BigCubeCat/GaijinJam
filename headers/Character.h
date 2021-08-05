#include "../headers/GameObject.h"
#include <box2d/box2d.h>

class Character : public GameObject {
public:
    Character(
        b2World &world, float x, float y, 
        float w, float h, float weight
    );
    float speed = 10.0f;
    b2World *world;
    bool animated = false; // TODO delete, when animation be ready
    std::string current_animation;
    std::map<std::string, Animation> animations;
    void Update();
    void Move(float x, float y);
};