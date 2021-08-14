//
// Created by bigcubecat on 14.08.2021.
//
#include "../headers/Game.h"
#include <SFML/Graphics.hpp>

class SceneManager {
private:
    std::vector<sf::Texture> textures;
public:
    Game *game;
    int currentScreen = 0;
    sf::Sprite StartScreenFirst;
    sf::Sprite StartScreenSecond;
    sf::Sprite LearnScreen;
    sf::Sprite LooseScreen;
    sf::Sprite WinScreen;
    SceneManager();
    void Update(sf::RenderWindow &window, float deltaTime);
    void ReloadGame(sf::RenderWindow &window);
    void LoadTexture(std::string fileName);
};