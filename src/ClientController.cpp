#include "../headers/ClientController.h"
#include <iostream>


ClientController::ClientController(b2World &world) {
    this->world = &world;
}

void ClientController::Update(float deltaTime) {
    this->spendedTime += deltaTime;
    if (this->spendedTime >= this->delayTime) {
        this->spendedTime = 0.0f;
        this->SpawnClient();
    }
    for (int i = this->clients.size() - 1; i >= 0; i--) {
        if (this->clients[i].needDestroy) {
            this->clients.erase(this->clients.begin()+i);
        } else {
            this->clients[i].Update(deltaTime);
        }
    }
}

void ClientController::SpawnClient() {
    auto spawn = this->spawnPoints[rand() % this->spawnPoints.size()];
    auto despawn = this->despawnPoints[rand() % this->despawnPoints.size()];
    Client newClient(*this->world, spawn.x, spawn.y, 50, 50, 50, despawn, 0, false);
    newClient.freeTime = MAXIMUM_FREE_TIME;
    this->clients.push_back(newClient);
}