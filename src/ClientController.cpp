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
            this->clients.erase(this->clients.begin()+(int)i);
        } else {
            this->clients[i].Update(deltaTime);
        }
    }
}

void ClientController::SpawnClient() {
    auto spawn = this->spawnPoints[rand() % this->spawnPoints.size()];
    auto despawn = this->despawnPoints[rand() % this->despawnPoints.size()];
    auto *newClient = new Client(*this->world,
        spawn.x, spawn.y, 50, 50, rand() % 200 + 50, despawn, 
        rand() % 14, false
    );
    newClient->freeTime = MAXIMUM_FREE_TIME;
    this->clients.emplace_back(*newClient);
}

void ClientController::Draw(sf::RenderWindow &window) {
    for (const Client& c : this->clients) {
        window.draw(c);
    }
}