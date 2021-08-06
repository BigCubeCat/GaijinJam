#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>


class CollisionListener : public b2ContactListener {
    void BeginContact(b2Contact *contact);
    void EndContact(b2Contact *contact);
};