#pragma once
#include "../headers/Client.h"
#include "../headers/Player.h"


class ClientController {
public:
    float spendedTime{};
    float delayTime = SPAWNER_TIME;
    std::vector<Client> clients;
    std::vector<sf::Vector2f> despawnPoints;
    PointMap *pointMap{};
    std::vector<sf::Vector2f> spawnPoints;
    b2World *world;
    Player *player;
    sf::RenderWindow *window;
    ClientController(b2World &world, sf::RenderWindow &window, Player &player, PointMap &pointMap);
    void Update(float deltaTime);
    void SpawnClient();
    void Draw();
};