#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Skeleton.h"

int main() {
    // ------ Initiale-------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1000,700), "Rpg Game",sf::Style::Default,settings);
    window.setFramerateLimit(144);
    Player player;
    Skeleton skeleton;
    player.Initialize();
    skeleton.Initialize();
    // ------ Load-------
    player.Load();
    skeleton.Load();
    // ------ Load-------
//---------------------------------------------------------------------main game loop
    sf::Clock clock;

    while (window.isOpen()) {
// -----------------------------------------------------------------------Update
        sf::Time deltaTimeTimer = clock.restart();
        float deltaTime = deltaTimeTimer.asMilliseconds();
        std::cout << deltaTime << std::endl;
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        skeleton.Update(deltaTime);
        player.Update(deltaTime,skeleton);



//------------------------------------------------------------------------Update
        //-------Draw-----
        window.clear(sf::Color::Black);
        player.Draw(window);
        skeleton.Draw(window);
        window.display();
        //-------Draw-----
    }

    return 0;
}