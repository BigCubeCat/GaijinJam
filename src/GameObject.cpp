#include "../headers/GameObject.h"
#include <iostream>

GameObject::GameObject(float x, float y, float w, float h) : sf::Sprite() {
    sf::Vector2f pos(x, y);
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
    std::cout << "pointer = ";
    std::cout << this->body->GetUserData().pointer << std::endl;
}

void GameObject::ReactToClass(int classType) {
    std::cout << "collision with " << classType << std::endl;
}

void GameObject::Update() {
    for (b2ContactEdge* ce = this->body->GetContactList(); ce; ce = ce->next) {
        std::cout << ce->other->GetUserData().pointer;
        try{
            int otherType = ce->other->GetUserData().pointer;
            this->ReactToClass(otherType);
        }
        catch (...) {
            std::cout << "ERROR\n";
        }
    }
}