#include <SFML/Graphics.hpp>
#include "../headers/Player.h"
#include <iostream>


b2Vec2 Gravity(0.f, 0.0f);

int main() {
    sf::RenderWindow *Window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Game", sf::Style::Default);
    sf::Clock *Clock;
    b2World *World = new b2World(Gravity);
    Window->setFramerateLimit(60);
    sf::Time last_time = Clock->getElapsedTime();
    sf::Sprite playerSprite;
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("assets/player.png")) {
        std::cout << "fuck" << std::endl;}
    playerSprite.setTexture(playerTexture);
    playerSprite.setColor(sf::Color(0, 255, 0)); // green
    playerSprite.setTextureRect(sf::IntRect(0, 0, 400, 400));
    playerSprite.setRotation(0.f);
    playerSprite.setPosition(100, 100);
    Player player(Window, Clock, World, 100, 100, playerSprite);
    
    while (Window->isOpen()) {
        sf::Event event;
        while (Window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) Window->close();
        }
        sf::Time timeNow = Clock->getElapsedTime();
        sf::Time deltaTime = timeNow - last_time;
        last_time = timeNow;
        World->Step(1 / SCALE, 8, 3);
        // Clear window
        Window->clear(sf::Color::White);
        //player.Update(deltaTime);
        Window->draw(player.getCurrentSprite());
        // Start drawing game arena
        Window->display();
    }
}