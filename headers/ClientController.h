#include "../headers/Client.h"


class ClientController {
public:
    float spendedTime;
    float delayTime = SPAWNER_TIME;
    std::vector<Client> clients;
    std::vector<sf::Vector2f> despawnPoints;
    std::vector<sf::Vector2f> spawnPoints;
    b2World *world;
    sf::RenderWindow *window;
    ClientController(b2World &world, sf::RenderWindow &window);
    void Update(float deltaTime);
    void SpawnClient();
    void Draw(sf::RenderWindow &window);
};