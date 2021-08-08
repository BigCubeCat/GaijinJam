#include "../headers/Client.h"


class ClientController {
public:
    int countClients;
    float spendedTime;
    float delayTime = SPAWNER_TIME;
    std::vector<Client> clients;
    std::vector<sf::Vector2f> despawnPoints;
    std::vector<sf::Vector2f> spawnPoints;
    b2World *world;
    ClientController(b2World &world);
    void Update(float deltaTime);
    void SpawnClient();
};