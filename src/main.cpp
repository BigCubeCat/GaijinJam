#include <SFML/Graphics.hpp>
#include "../headers/Player.h"
#include "../headers/Wall.h"
#include "../headers/Helper.h"
#include "../headers/ClientController.h"
#include <iostream>
#include <list>
#include <map>


b2Vec2 Gravity(0.f, 0.0f);


int main(void) {
    sf::RenderWindow Window(sf::VideoMode(1920, 1080), "Game", sf::Style::Default);
    b2World World(Gravity);
    sf::Clock clock;
    Window.setFramerateLimit(60);
    sf::Texture MapTexture;
    MapTexture.loadFromFile("assets/Map.png");
    std::list<Wall> mainWallList;
    std::list<Wall> mapWallList;
    int mapNumber = 1;
    makeMap("resources/maps.txt", mapNumber, mainWallList, mapWallList, World);
    GameObject Map(50, 50, 1920, 1080);
    Map.setTexture(MapTexture);
    Player player(World, 500, 500);
    ClientController controller(World);
    std::vector<sf::Vector2f> spawns;
    std::vector<sf::Vector2f> despawns;
    spawns.push_back(sf::Vector2f{100, 100});
    spawns.push_back(sf::Vector2f{700, 500});
    despawns.push_back(sf::Vector2f{400, 400});
    despawns.push_back(sf::Vector2f{300, 300});
    controller.spawnPoints = spawns;
    controller.despawnPoints = despawns;
    Client client(World, 100, 100, 50, 50, 100, sf::Vector2f{300, 300}, 0, false);
    while (Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) Window.close();
        }
        World.Step(1 / SCALE, 8, 3); // Update Box2D world

        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

        Window.clear(sf::Color::White);
        controller.Update(deltaTime);
        player.Update(deltaTime);
        Window.draw(player);
        client.Update(deltaTime);
        Window.draw(client);
        int a = 0;
        for (Client client : controller.clients) {
            a++;
            Window.draw(client);
        }
        std::cout << "count = " << a << std::endl;
        Window.draw(Map);
        Window.display();
    }
}