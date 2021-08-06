#include "../headers/CollisionListener.h"
#include "../headers/GameObject.h"


void CollisionListener::BeginContact(b2Contact *contact) {
    b2Body* body1 = contact->GetFixtureA()->GetBody();
    b2Body* body2 = contact->GetFixtureB()->GetBody();
    auto firstObject = body1->GetUserData().pointer;
    auto secondObject = body1->GetUserData().pointer;
    GameObject actorA = *reinterpret_cast<GameObject*>(firstObject);
    GameObject actorB = *reinterpret_cast<GameObject*>(secondObject);
    actorA.OnCollisionBegin(actorB.TypeIndex);
    actorB.OnCollisionBegin(actorA.TypeIndex);
}

void CollisionListener::BeginContact(b2Contact *contact) {
    b2Body* body1 = contact->GetFixtureA()->GetBody();
    b2Body* body2 = contact->GetFixtureB()->GetBody();
    auto firstObject = body1->GetUserData().pointer;
    auto secondObject = body1->GetUserData().pointer;
    GameObject actorA = *reinterpret_cast<GameObject*>(firstObject);
    GameObject actorB = *reinterpret_cast<GameObject*>(secondObject);
    actorA.OnCollisionEnd(actorB.TypeIndex);
    actorB.OnCollisionEnd(actorA.TypeIndex);
}
