#include <SFML/Graphics.hpp>
#include "../headers/Player.h"


b2Vec2 Gravity(0.f, 0.0f);

int main() {
    sf::RenderWindow Window(sf::VideoMode(1920, 1080), "Game", sf::Style::Default);
    b2World World(Gravity);
    sf::Clock clock;
    sf::Time time = clock.getElapsedTime();
    Window.setFramerateLimit(60);
    
    sf::Texture mapTexture;
    sf::Texture playerTexture;
    sf::Texture chTexture;
    playerTexture.loadFromFile("assets/characters/player.png");
    chTexture.loadFromFile("assets/player.png");
    mapTexture.loadFromFile("assets/bg.png");
       
    sf::Sprite Map;
    Map.setTexture(mapTexture);
    Map.setScale(sf::Vector2f(0.5, 0.5f));
    Player player(World, 100, 100);
    Character character1(World, 600, 600, PLAYER_DIAMETR, PLAYER_DIAMETR, 1000);
    player.setTexture(playerTexture);
    character1.setTexture(playerTexture);
    while (Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) Window.close();
        }
        World.Step(1 / SCALE, 8, 3);
        // Clear window
        Window.clear(sf::Color::White);
        Window.draw(Map);
        player.Update();
        character1.Update();
        Window.draw(player);
        Window.draw(character1);
        Window.display();
    }
}