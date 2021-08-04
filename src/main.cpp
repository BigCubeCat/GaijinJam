#include <SFML/Graphics.hpp>
#include "../headers/constants.h"
#include "../headers/LayerSystem.h"


int main() {
    Window.setFramerateLimit(60);
    LayerSystem layers();
    
    while (Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) Window.close();
        }
        World.Step(1 / SCALE, 8, 3);
        // Clear window
        Window.clear(sf::Color::White);
        // Start drawing game arena
        // 
        Window.display();
    }
}