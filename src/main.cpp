#include "../headers/Game.h"


int main(void) {
    sf::RenderWindow Window(sf::VideoMode(1920, 1080), "Game", sf::Style::Fullscreen);
    Window.setFramerateLimit(60);

    sf::SoundBuffer musicBuffer;
    musicBuffer.loadFromFile("../assets/sounds/music.ogg");
    sf::Sound Music;
    Music.setBuffer(musicBuffer);
    Music.setLoop(true);
    Music.setVolume(75.0f);
    Music.play();

    Game game;
    game.Setup(Window);
    sf::Clock clock;

    float deltaTime;
    while (Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) Window.close();
            if (event.type == sf::Event::KeyReleased || event.type == sf::Event::JoystickButtonReleased)
                game.keyReleased = true;
        }
        deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();
        game.Update(Window, deltaTime);
        Window.display();
    }
}