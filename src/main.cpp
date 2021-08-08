#include <SFML/Graphics.hpp>
#include "../headers/Player.h"
#include "../headers/Wall.h"
#include "../headers/Client.h"
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
    playerTexture.loadFromFile("assets/characters/player.png");
    chTexture.loadFromFile("assets/characters/aN.png");
    MapTexture.loadFromFile(("assets/Map.png"));
    std::list <Wall> mainWallList;
    std::list <std::list<Wall>> mapWallList;
    Player player(World, 500, 500);
    player.setTexture(playerTexture);

    std::vector<sf::Vector2f> points;
    points.push_back(sf::Vector2f{200, 200});
    points.push_back(sf::Vector2f{100, 155});

    //Client character1(World, 100, 100, PLAYER_DIAMETR, PLAYER_DIAMETR, 70, points, true);
    GameObject Map(50, 50, 1920, 1080, 0);
    Wall mainWall1(World, 25, 540, 0.1, 540);
    Wall mainWall2(World, 960, 25, 960, 0.1);
    Wall mainWall3(World, 1945, 540, 0.1, 540);
    Wall mainWall4(World, 960, 1105, 960, 0.1);
    Wall wall1(World, 1760, 325, 155, 40);
    Wall wall2 (World, 1615, 380, 10, 80);
    Wall wall3(World, 1550, 425, 50, 35);
    Wall wall4(World, 1518, 535, 18, 82);
    Wall wall5(World, 1518, 815, 15, 70);
    Wall wall6(World, 1713, 843, 210, 42);
    
    Client client(World, 500, 100, 50, 50, 100, sf::Vector2f{800, 500}, false);

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
        client.Update(deltaTime);
        Window.draw(client);
        Window.draw(player);
        Window.draw(Map);
        Window.display();
    }
}