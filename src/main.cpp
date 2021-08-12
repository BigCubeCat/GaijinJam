#include <SFML/Graphics.hpp>
#include "../headers/Player.h"
#include "../headers/Slider.h"
#include "../headers/Wall.h"
#include "../headers/Helper.h"
#include "../headers/ClientController.h"
#include "../headers/FPS.h"
#include <iostream>
#include <list>
#include <map>
#include <sstream>



b2Vec2 Gravity(0.f, 0.0f);


int main(void) {
    sf::RenderWindow Window(sf::VideoMode(1920, 1080), "Game", sf::Style::Default);
    b2World World(Gravity);
    FPS fps;
    sf::Clock clock;
    Window.setFramerateLimit(60);
    sf::Texture MapTexture;
    sf::Texture bgTexture;
    sf::Texture pTexture;
    sf::Texture sliderTexture;
    pTexture.loadFromFile("../assets/UI/p.png");
    MapTexture.loadFromFile("../assets/Map.png");
    bgTexture.loadFromFile("../assets/floor.png");
    sliderTexture.loadFromFile("../assets/UI/slider.png");
    std::list<Wall> mainWallList;
    std::list<Wall> mapWallList;
    int mapNumber = 1;
    makeMap("../resources/maps.txt", mapNumber, mainWallList, mapWallList, World);
    GameObject BG(50, 50, 1920, 1080);
    GameObject SliderMain(600, 0, 300, 50);
    GameObject Map(960, 20, 1920, 1080);
    Map.setTexture(MapTexture);
    BG.setTexture(bgTexture);
    SliderMain.setTexture(pTexture);
    Player player(World, 500, 500, Sensor(World, 500, 500, BLAST_RADIUS));
    Slider slider(600, 70, 300, 50, player);
    slider.setTexture(sliderTexture);
    ClientController controller(World, Window, player);
    std::vector<sf::Vector2f> spawns;
    std::vector<sf::Vector2f> despawns;
    spawns.emplace_back(sf::Vector2f{1000, 75});
    spawns.emplace_back(sf::Vector2f{900, 75});
    spawns.emplace_back(sf::Vector2f{1200, 75});
    despawns.emplace_back(sf::Vector2f{20, 500});
    despawns.emplace_back(sf::Vector2f{500, 800});
    despawns.emplace_back(sf::Vector2f{1000, 800});
    despawns.emplace_back(sf::Vector2f{1900, 800});
    despawns.emplace_back(sf::Vector2f{1900, 500});
    controller.spawnPoints = spawns;
    controller.despawnPoints = despawns;

    while (Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) Window.close();
        }
        World.Step(1 / SCALE, 8, 3); // Update Box2D world

        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

        Window.clear(sf::Color::Black);
        Window.draw(BG);
        // игрок должен обновляться раньше контроллеров!!!
        player.Update(deltaTime);
        Window.draw(player);
        controller.Update(deltaTime);
        controller.Draw();
        Window.draw(Map);
        SliderMain.Update();
        slider.Update();
        Window.draw(SliderMain);
        Window.draw(slider);
        Window.display();

        fps.update();
        std::ostringstream ss;
        ss << fps.getFPS();
        std::cout << player.score << std::endl;
        Window.setTitle(ss.str());
    }
}