#include "../headers/SceneManager.h"

SceneManager::SceneManager() {
    std::cout << "GGGGG\n";
    this->LoadTexture("../assets/screens/first.png");
    this->LoadTexture("../assets/screens/second.png");
    this->LoadTexture("../assets/screens/help.png");
    this->LoadTexture("../assets/screens/win.png");
    this->LoadTexture("../assets/screens/loose.png");
    this->StartScreenFirst.setTexture(this->textures[0]);
    this->StartScreenSecond.setTexture(this->textures[1]);
    this->LearnScreen.setTexture(this->textures[2]);
    this->WinScreen.setTexture(this->textures[3]);
    this->LooseScreen.setTexture(this->textures[4]);
}

void SceneManager::Update(sf::RenderWindow &window, float deltaTime) {
    std::cout << "current screen = " << this->currentScreen << std::endl;
    switch (this->currentScreen) {
        case GAME_SCREEN:
            this->game->Update(window, deltaTime);
            if (this->game->GameOver) {
                this->ReloadGame(window);
            }
            break;
        case WIN_SCREEN:
            window.draw(this->WinScreen);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                this->currentScreen = GAME_SCREEN;
            }
            break;
        case LOOSE_SCREEN:
            window.draw(this->LooseScreen);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                this->currentScreen = GAME_SCREEN;
            }
            break;
        case START_SCREEN_FIRST:
            window.draw(this->StartScreenFirst);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                this->currentScreen = START_SCREEN_SECOND;
            }
            break;
        case START_SCREEN_SECOND:
            window.draw(this->StartScreenSecond);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                this->currentScreen = LEARN_SCREEN;
            }
            break;
        case LEARN_SCREEN:
            window.draw(this->LearnScreen);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                this->currentScreen = GAME_SCREEN;
                this->ReloadGame(window);
            }
            break;
    }
}

void SceneManager::ReloadGame(sf::RenderWindow &window) {
    this->game->Setup(window);
    this->currentScreen = this->game->win ? WIN_SCREEN : LOOSE_SCREEN;
}

void SceneManager::LoadTexture(std::string fileName) {
    auto *tex = new sf::Texture();
    tex->loadFromFile(fileName);
    this->textures.emplace_back(*tex);
}
