#include <SFML/Graphics.hpp>
#include <iostream>
#include "FrameRate.h"
#include "Player.h"
#include "Skeleton.h"
int main() {
    // ------ Initiale-------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Rpg Game",sf::Style::Default,settings);
    window.setVerticalSyncEnabled(true);
    Player player;
    Skeleton skeleton;
    FrameRate framerate;
    player.Initialize();
    skeleton.Initialize();
    framerate.Initialize();


    // ------ Load-------
    player.Load();
    skeleton.Load();
    framerate.Load();


    // ------ Load-------
//---------------------------------------------------------------------main game loop
    sf::Clock clock;
    while (window.isOpen()) {
// -----------------------------------------------------------------------Update
        sf::Time deltaTimeTimer = clock.restart();
        double deltaTime = deltaTimeTimer.asMicroseconds()/1000.0;


        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        skeleton.Update(deltaTime);
        player.Update(deltaTime,skeleton);
        framerate.Update(deltaTime);



//------------------------------------------------------------------------Update
        //-------Draw-----
        window.clear(sf::Color::Black);
        player.Draw(window);
        skeleton.Draw(window);
        framerate.Draw(window);
        window.display();
        //-------Draw-----
    }

    return 0;
}