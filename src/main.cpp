#include "../headers/Game.h"


int main(void) {
    sf::RenderWindow Window(sf::VideoMode(1920, 1080), "Game", sf::Style::Default);
    Window.setFramerateLimit(60);

    sf::SoundBuffer musicBuffer;
    musicBuffer.loadFromFile("../assets/sounds/music.ogg");
    sf::Sound Music;
    Music.setBuffer(musicBuffer);
    Music.setLoop(true);
    Music.play();

    Game game;
    game.Setup(Window);
    sf::Clock clock;

    float deltaTime;
    while (Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) Window.close();
        }
        deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

        game.Update(Window, deltaTime);
        std::cout << game.currentScreen << std::endl;
        Window.display();
    }
}