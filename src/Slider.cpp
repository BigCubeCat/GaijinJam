#include "../headers/Slider.h"
#include <iostream>


Slider::Slider(float minX, float maxX, float x, float y, float w, float h, Player &p) : GameObject(x, y, w, h){
    this->player = &p;
    this->minX = x;
    this->maxX = maxX;
    this->minX = minX;
    this->scale = w / (maxX - minX);
    this->middle = x + maxX;
    std::cout << this->middle << std::endl;
}

void Slider::Update() {
    this->x = this->middle + (this->player->score * this->scale);
    GameObject::Update();
}