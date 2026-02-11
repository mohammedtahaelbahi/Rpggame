#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
int main() {




    std::vector <int> yasin;
    yasin.push_back(1);
    yasin.push_back(2);
    yasin.push_back(3);
    yasin.push_back(4);
    yasin.push_back(5);
    for (int i=0;i<yasin.size();i++) {
        std::cout <<yasin[i]<<"\n";
    }







    // ------ Initiale-------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Rpg Game",sf::Style::Default,settings);


    // ------ Initiale-------
//----------------------------------------------------------------------------Load Skeleton

    sf::Texture skeleton_texture;
    sf::Sprite enemy_sprite;
    if (skeleton_texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")){
        std::cout <<"Image enemy loaded\n";
        enemy_sprite.setTexture(skeleton_texture);
        enemy_sprite.setPosition(sf::Vector2f(400,600));
        int XIndex{0}, YIndex{2};


        enemy_sprite.setTextureRect(sf::IntRect(XIndex *64 ,YIndex * 64,64,64));

        enemy_sprite.scale(sf::Vector2f(2,2));
    }
    else {
        std::cout <<"Image enemy texture could not be loaded\n";
    }
//----------------------------------------------------------------------------Load Skeleton
//----------------------------------------------------------------------------Load Player
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if(playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
        playerSprite.setTexture(playerTexture);
        int XIndex{0}, YIndex{3};


        std::cout <<"Image player loaded\n";
        playerSprite.setTextureRect(sf::IntRect(XIndex *64 ,YIndex * 64,64,64));

        playerSprite.scale(sf::Vector2f(2,2));
    }
    else {
        std::cout <<"Image player texture could not be loaded\n";
    }
//----------------------------------------------------------------------------Load Player


//---------------------------------------------------------------------main game loop
    while (window.isOpen()) {

// -----------------------------------------------------------------------Update

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            playerSprite.setPosition(position + sf::Vector2f(1,0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            playerSprite.setPosition(position + sf::Vector2f(-1,0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            playerSprite.setPosition(position + sf::Vector2f(0,-1));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::
            S)) {
            playerSprite.setPosition(position + sf::Vector2f(0,1));
        }

//------------------------------------------------------------------------Update


        //-------Draw-----
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.draw(enemy_sprite);
        window.display();
        //-------Draw-----
    }

    return 0;
}
