#include <SFML/Graphics.hpp>
#include "../headers/Player.h"


b2Vec2 Gravity(0.f, 0.0f);

int main() {
    sf::RenderWindow Window(sf::VideoMode(1920, 1080), "Game", sf::Style::Default);
    b2World World(Gravity);
    sf::Clock clock;
    sf::Time time = clock.getElapsedTime();
    Window.setFramerateLimit(60);
    sf::Sprite playerSprite;
    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets/player.png");
       
    Player player(World, 100, 100);
    player.setTexture(playerTexture);
    while (Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) Window.close();
        }
        World.Step(1 / SCALE, 8, 3);
        // Clear window
        Window.clear(sf::Color::White);
        player.Update();
        Window.draw(player);
        Window.display();
    }
}