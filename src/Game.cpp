#include "../headers/Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <list>

void Game::Setup(sf::RenderWindow &window) {
    b2Vec2 Gravity(0, 0);

    this->world = new b2World(Gravity);

    this->LoadTexture("../assets/UI/p.png");
    this->LoadTexture("../assets/UI/slider.png");
    this->LoadTexture("../assets/Map.png");
    this->LoadTexture("../assets/floor.png");
    this->LoadTexture("../assets/screens/first.png");
    this->LoadTexture("../assets/screens/second.png");
    this->LoadTexture("../assets/screens/win.png");
    this->LoadTexture("../assets/screens/loose.png");

    int mapNumber = 1;
    makeMap("../resources/maps.txt", mapNumber, this->mainWallList, this->mapWallList, *this->world);

    this->player = new Player(*this->world, 500, 500, Sensor(*this->world, 500, 500, BLAST_RADIUS));
    this->clientController = new ClientController(*this->world, window, *this->player);
    this->slider = new Slider(-SCORE, SCORE, 840, 50, 360, 1080, *this->player);
    this->slider->setScale(0.6, 0.6);

    vector<sf::Vector2f> spawns;
    vector<sf::Vector2f> despawns;

    spawns.emplace_back(sf::Vector2f{1000, 75});
    spawns.emplace_back(sf::Vector2f{900, 75});
    spawns.emplace_back(sf::Vector2f{1200, 75});

    despawns.emplace_back(sf::Vector2f{145, 635});
    despawns.emplace_back(sf::Vector2f{295, 1005});
    despawns.emplace_back(sf::Vector2f{1075, 1015});
    despawns.emplace_back(sf::Vector2f{295, 1005});
    despawns.emplace_back(sf::Vector2f{1770, 585});

    this->clientController->spawnPoints = spawns;
    this->clientController->despawnPoints = despawns;

    this->BG = new GameObject(50, 50, 1920, 1080);
    this->SliderMain = new GameObject(746, 0, 1920, 1080);
    this->Map = new GameObject(100, 20, 1920, 1080);

    this->SliderMain->setTexture(this->allTextures[0]);
    this->SliderMain->setScale(0.5, 0.5);
    this->slider->setTexture(this->allTextures[1]);
    this->Map->setTexture(this->allTextures[2]);
    this->BG->setTexture(this->allTextures[3]);
}

void Game::Update(sf::RenderWindow &window, float deltaTime) {
    this->world->Step(1 / SCALE, 8, 3);

    window.clear(sf::Color::Black);
    if (this->currentScreen == GAME_SCREEN) {
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
        if (player->score <= -SCORE) {
            this->player->score = 0;
            this->GameOver = true;
            this->win = false;
            this->currentScreen = LOOSE_SCREEN;
        } else if (player->score >= SCORE) {
            this->player->score = 0;
            this->GameOver = true;
            this->win = true;
            this->currentScreen = WIN_SCREEN;
        }
    } else if (this->currentScreen <= LEARN_SCREEN) {
        this->screenSprite.setTexture(this->allTextures[this->currentScreen + 4]);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->keyReleased) {
            this->keyReleased = false;
            this->currentScreen++;
        }
        window.draw(this->screenSprite);
    } else if (this->currentScreen == WIN_SCREEN || this->currentScreen == LOOSE_SCREEN) {
        this->screenSprite.setTexture(this->allTextures[this->currentScreen + 4]);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            this->ClearGame();
            this->currentScreen = GAME_SCREEN;
        }
        window.draw(this->screenSprite);
    }

    window.display();
}

void Game::LoadTexture(const string& fileName) {
    auto *tex = new sf::Texture();
    tex->loadFromFile(fileName);
    this->allTextures.emplace_back(*tex);
}

Game::Game() {

}

void Game::ClearGame() {
    for (int i = this->clientController->clients.size() - 1; i >= 0; i--) {
        this->world->DestroyBody(this->clientController->clients[i].body);
        this->clientController->clients.erase(this->clientController->clients.begin()+(int)i);
    }
}
