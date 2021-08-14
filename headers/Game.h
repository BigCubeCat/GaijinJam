#pragma  once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

using namespace std;

class Game {
public:
    FPS *fps;
    b2World *world;
    sf::Clock *clock;
    vector<sf::Texture> allTextures;
    vector<sf::SoundBuffer> allSounds;
    list<Wall> mainWallList;
    list<Wall> mapWallList;
    
    Player *player;
    ClientController *clientController;

    sf::SoundBuffer musicBuffer;
    sf::Sound Music;

    bool GameOver = false;
    bool win = false;
    
    Slider *slider;
    GameObject *BG;
    GameObject *Map;
    GameObject *SliderMain;
    Game();
    void Setup(sf::RenderWindow&);
    void Update(sf::RenderWindow&, float);
    void LoadTexture(const string& fileName);
};