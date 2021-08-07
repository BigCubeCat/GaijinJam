#include "../headers/GameObject.h"
#include <iostream>

GameObject::GameObject(float x, float y, float w, float h, int typeIndex=0) : sf::Sprite() {
    sf::Vector2f pos(x, y);
    this->TypeIndex = TypeIndex;
    this->position = pos;
    this->height = h;
    this->width = w;
}

sf::Vector2f GameObject::GetBodyPosition() {
    return sf::Vector2f{this->body->GetPosition().x * SCALE, this->body->GetPosition().y * SCALE};
}

void GameObject::SetBody(b2Body *body) {
    this->body = body;
    this->body->GetUserData().pointer = this->TypeIndex;
}

void GameObject::ReactToClass(int classType) {
    std::cout << this->TypeIndex <<  " collision with " << classType << std::endl;
}

void GameObject::Update() {
    for (b2ContactEdge* ce = this->body->GetContactList(); ce; ce = ce->next) {
        try{
            int otherType = ce->other->GetUserData().pointer;
            this->ReactToClass(otherType);
        }
        catch (...) {
            std::cout << "ERROR\n";
        }
    }
}