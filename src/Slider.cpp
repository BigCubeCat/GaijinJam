#include "../headers/Slider.h"


Slider::Slider(float x, float y, float w, float h, Player &p) : GameObject(x, y, w, h){
    this->player = &p;
    this->minX = x;
    this->maxX = w * 2 + this->minX;
}

void Slider::Update() {
    GameObject::Update();
    this->x = this->minX + (this->maxX - this->minX) / 2 + player->score; 
}