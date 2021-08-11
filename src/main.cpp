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
    sf::Texture bgTexture;
    MapTexture.loadFromFile("assets/Map.png");
    bgTexture.loadFromFile("assets/bg.png");
    std::list<Wall> mainWallList;
    std::list<Wall> mapWallList;
    int mapNumber = 1;
    makeMap("resources/maps.txt", mapNumber, mainWallList, mapWallList, World);
    GameObject BG(50, 50, 1920, 1080);
    GameObject Map(50, 50, 1920, 1080);
    Map.setTexture(MapTexture);
    Player player(World, 500, 500, Sensor(World, 500, 500, BLAST_RADIUS));
    ClientController controller(World, Window);
    std::vector<sf::Vector2f> spawns;
    std::vector<sf::Vector2f> despawns;
    spawns.push_back(sf::Vector2f{1000, 0});
    despawns.push_back(sf::Vector2f{20, 500});
    despawns.push_back(sf::Vector2f{500, 800});
    despawns.push_back(sf::Vector2f{1000, 800});
    despawns.push_back(sf::Vector2f{1900, 800});
    despawns.push_back(sf::Vector2f{1900, 500});
    controller.spawnPoints = spawns;
    controller.despawnPoints = despawns;

    Client newClient(World, 100, 100, 50, 50, rand() % 300 + 50, sf::Vector2f{200, 200}, 0, false);
    newClient.freeTime = MAXIMUM_FREE_TIME;

    while (Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) Window.close();
        }
        World.Step(1 / SCALE, 8, 3); // Update Box2D world

        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

        Window.clear(sf::Color::Black);
        controller.Update(deltaTime);
        controller.Draw(Window);
        player.Update(deltaTime);
        Window.draw(player);
        newClient.Update(deltaTime);
        Window.draw(newClient);
        Window.draw(Map);
        Window.display();
    }
}