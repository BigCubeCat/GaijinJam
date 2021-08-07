#include <SFML/Graphics.hpp>
#include "../headers/Player.h"
#include "../headers/Wall.h"
#include "../headers/Client.h"
#include "../headers/CollisionListener.h"
#include <iostream>
#include <list>
#include <map>
b2Vec2 Gravity(0.f, 0.0f);


int main(void) {
    sf::RenderWindow Window(sf::VideoMode(1920, 1080), "Game", sf::Style::Default);
    b2World World(Gravity);
    sf::Clock clock;
    sf::Time time = clock.getElapsedTime();
    Window.setFramerateLimit(60);

    sf::Texture mapTexture;
    sf::Texture playerTexture;
    sf::Texture chTexture;
    sf::Texture MapTexture;
    playerTexture.loadFromFile("../assets/PlayerW.png");
    chTexture.loadFromFile("../assets/CharWO1.png");
    MapTexture.loadFromFile(("../assets/Map.png"));
    std::list <Wall> mainWallList;
    std::list <std::list<Wall>> mapWallList;
    Player player(World, 500, 500);

    std::vector<sf::Vector2f> points;
    points.push_back(sf::Vector2f{200, 200});
    points.push_back(sf::Vector2f{100, 155});
    points.push_back(sf::Vector2f{500, 300});
    points.push_back(sf::Vector2f{300, 800});
    points.push_back(sf::Vector2f{200, 200});
    points.push_back(sf::Vector2f{800, 200});

    Client character1(World, 100, 100, PLAYER_DIAMETR, PLAYER_DIAMETR, 70, points, true);
    character1.lastPoint = sf::Vector2f{800, 800};
    GameObject Map(50, 50, 1920, 1080);
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

    //player.setTexture(playerTexture);
    //character1.setTexture(chTexture);
    Map.setTexture(MapTexture);
    //wall1.setTexture(chTexture);
    while (Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) Window.close();
        }
        World.Step(1 / SCALE, 8, 3);
        Window.clear(sf::Color::White);
        player.Update();
        std::cout << player.x << " : " << player.y << std::endl;
        character1.Update();
        //Window.draw(player);
       // Window.draw(character1);
        Window.draw(Map);
        //Window.draw(wall1);
        Window.display();
    }
}