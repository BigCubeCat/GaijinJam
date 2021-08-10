#include "../headers/ClientController.h"
#include <iostream>


ClientController::ClientController(b2World &world, sf::RenderWindow &window) {
    this->world = &world;
    this->window = &window;
    this->delayTime = SPAWNER_TIME;
}

void ClientController::Update(float deltaTime) {
    this->spendedTime += deltaTime;
    if (this->spendedTime >= this->delayTime) {
        this->spendedTime = 0.0f;
        this->SpawnClient();
    }
    for (int i = this->clients.size() - 1; i >= 0; i--) {
        if (this->clients[i].needDestroy) {
            this->world->DestroyBody(this->clients[i].body);
            this->clients.erase(this->clients.begin()+i);
        } else {
            this->clients[i].Update(deltaTime);
            this->window->draw(this->clients[i]);
        }
    }
}

void ClientController::SpawnClient() {
    auto spawn = this->spawnPoints[rand() % this->spawnPoints.size()];
    auto despawn = this->despawnPoints[rand() % this->despawnPoints.size()];
    Client newClient(*this->world, spawn.x, spawn.y, 50, 50, rand() % 300 + 50, despawn, this->clients.size() % 3, false);
    newClient.freeTime = MAXIMUM_FREE_TIME;
    std::cout << newClient.getTexture() << std::endl;
    this->clients.push_back(newClient);
}