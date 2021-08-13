#include "../headers/Game.h"



int main(void) {
    sf::RenderWindow Window(sf::VideoMode(1920, 1080), "Game", sf::Style::Default);
    Window.setFramerateLimit(40);
 
    Game game;
    sf::Clock clock;
    game.Setup(Window);

    while (Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) Window.close();
        }

        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();
        game.Update(Window, deltaTime);
    }
}