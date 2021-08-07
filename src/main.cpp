#include <SFML/Graphics.hpp>
#include "../headers/Player.h"
#include "../headers/Wall.h"
#include "../headers/Client.h"
#include "../headers/Helper.h"
#include <iostream>
#include <list>
#include <map>


b2Vec2 Gravity(0.f, 0.0f);


int main(void) {
    sf::RenderWindow Window(sf::VideoMode(1920, 1080), "Game", sf::Style::Default);
    b2World World(Gravity);
    sf::Clock clock;
    Window.setFramerateLimit(60);

    sf::Texture mapTexture;
    sf::Texture playerTexture;
    sf::Texture chTexture;
    sf::Texture MapTexture;
    playerTexture.loadFromFile("../assets/characters/player.png");
    chTexture.loadFromFile("../assets/characters/aN.png");
    MapTexture.loadFromFile(("../assets/Map.png"));
    std::list<Wall> mainWallList;
    std::list<Wall> mapWallList;
    int mapNumber = 1;
    makeMap("D:\\Programms\\Programm C++\\GaijinJam\\resources\\maps.txt", mapNumber, mainWallList, mapWallList,
            World);
    Player player(World, 500, 500);
    player.setTexture(playerTexture);

    std::vector<sf::Vector2f> points;
    points.push_back(sf::Vector2f{200, 200});
    points.push_back(sf::Vector2f{100, 155});

    //Client character1(World, 100, 100, PLAYER_DIAMETR, PLAYER_DIAMETR, 70, points, true);
    GameObject Map(50, 50, 1920, 1080, 0);
    Map.setTexture(MapTexture);
    while (Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) Window.close();
        }
        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

        World.Step(1 / SCALE, 8, 3); // Update Box2D world
        Window.clear(sf::Color::White);
        player.Update(deltaTime);
        Window.draw(player);
        Window.draw(Map);
        Window.display();
    }
}