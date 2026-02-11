#include <SFML/Graphics.hpp>
#include <iostream>
int main() {
    // ------ Initiale-------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1280,720), "Rpg Game",sf::Style::Default,settings);


    // ------ Initiale-------

    //-------Load---------

    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if(playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
        std::cout <<"Image player loaded\n";
        playerSprite.setTexture(playerTexture);
        int XIndex{1}, YIndex{2};


        playerSprite.setTextureRect(sf::IntRect(XIndex *64 ,YIndex * 64,64,64));

        playerSprite.scale(sf::Vector2f(2,2));
    }


    //-------Load---------
//main game loop
    while (window.isOpen()) {

        // -----------Update---------

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            /*if (event.type == event.KeyPressed) {
                if (event.key.code == sf::Keyboard:: F) {

                    //0,0

                    sf::Vector2f position = playerSprite.getPosition();
                    playerSprite.setPosition(position + sf::Vector2f(10,0));
                }
            } */


        }
        sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            playerSprite.setPosition(position + sf::Vector2f(0.5,0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            playerSprite.setPosition(position + sf::Vector2f(-0.5,0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            playerSprite.setPosition(position + sf::Vector2f(0,-0.5));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::
            S)) {
            playerSprite.setPosition(position + sf::Vector2f(0,0.5));
        }


        // -----------Update---------


        //-------Draw-----
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.display();
        //-------Draw-----
    }

    return 0;
}
