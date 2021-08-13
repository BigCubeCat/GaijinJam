#include "../headers/Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <list>


void Game::Setup(sf::RenderWindow &window) {
    b2Vec2 Gravity(0.f, 0.0f);
    this->world = new b2World(Gravity);

    this->LoadTexture("../assets/UI/p.png");
    this->LoadTexture("../assets/UI/slider.png");
    this->LoadTexture("../assets/Map.png");
    this->LoadTexture("../assets/floor.png");

    int mapNumber = 1;
    makeMap("../resources/maps.txt", mapNumber, this->mainWallList, this->mapWallList, *this->world);

    this->player = new Player(*this->world, 500, 500, Sensor(*this->world, 500, 500, BLAST_RADIUS));
    this->clientController = new ClientController(*this->world, window, *this->player);
    this->slider = new Slider(600, 70, 300, 50, *this->player);
    vector<sf::Vector2f> spawns;
    vector<sf::Vector2f> despawns;
    spawns.emplace_back(sf::Vector2f{1000, 75});
    spawns.emplace_back(sf::Vector2f{900, 75});
    spawns.emplace_back(sf::Vector2f{1200, 75});
    despawns.emplace_back(sf::Vector2f{125, 580});
    despawns.emplace_back(sf::Vector2f{275, 950});
    despawns.emplace_back(sf::Vector2f{1055, 950});
    despawns.emplace_back(sf::Vector2f{1670, 970});
    despawns.emplace_back(sf::Vector2f{1750, 535});
    this->clientController->spawnPoints = spawns;
    this->clientController->despawnPoints = despawns;

    this->BG = new GameObject(50, 50, 1920, 1080);
    this->SliderMain = new GameObject(600, 0, 300, 50);
    this->Map = new GameObject(960, 20, 1920, 1080);

    this->SliderMain->setTexture(this->allTextures[0]);
    this->slider->setTexture(this->allTextures[1]);
    this->Map->setTexture(this->allTextures[2]);
    this->BG->setTexture(this->allTextures[3]);

    this->musicBuffer.loadFromFile("../assets/sounds/music.wav");
    this->Music.setBuffer(this->musicBuffer);
    this->Music.setLoop(true);
    this->Music.play();
}

void Game::Update(sf::RenderWindow &window, float deltaTime) {
    this->world->Step(1 / SCALE, 8, 3);

    window.clear(sf::Color::Black);
    window.draw(*this->BG);
    // игрок должен обновляться раньше контроллеров!!!
    this->player->Update(deltaTime);
    this->clientController->Update(deltaTime);
    this->SliderMain->Update();
    this->slider->Update();

    window.draw(*this->player);
    this->clientController->Draw();
    window.draw(*this->Map);
    window.draw(*this->SliderMain);
    window.draw(*this->slider);

    window.display();
}

void Game::LoadTexture(const string& fileName) {
    auto *tex = new sf::Texture();
    tex->loadFromFile(fileName);
    this->allTextures.emplace_back(*tex);
}

Game::Game() {

}
