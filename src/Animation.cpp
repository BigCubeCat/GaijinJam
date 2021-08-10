#include "../headers/Animation.h"

void Animation::Tick(float deltaTime) {
    this->spendedTime += deltaTime;
    if (this->getFrame().second <= this->spendedTime) {
        this->spendedTime = 0.0f;
        this->currentTexture = (this->currentTexture + 1) % this->frames[this->currentAnimation].size();
    }
}

int Animation::GetTexture() {
    return this->getFrame().first;
}

pair<int, float> Animation::getFrame() {
    return this->frames[this->currentAnimation][this->currentTexture];
}
