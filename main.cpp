#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

sf::Vector2f normalizeVector(sf::Vector2f v) {

    float m = std::sqrt(v.x * v.x + v.y * v.y);
    sf::Vector2f normalizedvector;
    normalizedvector.x = v.x / m;
    normalizedvector.y = v.y / m;
    return normalizedvector;


}


int main() {
        // ------ Initiale-------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Rpg Game",sf::Style::Default,settings);


    // ------ Initiale-------

        std::vector<sf::RectangleShape> bullets;

    [[maybe_unused]] float SpeedBullet = 0.1f;


//----------------------------------------------------------------------------Load Skeleton



    sf::Texture skeleton_texture;
    sf::Sprite skeleton_sprite;
    if (skeleton_texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")){
        std::cout <<"Image enemy loaded\n";
        skeleton_sprite.setTexture(skeleton_texture);
        skeleton_sprite.setPosition(sf::Vector2f(400,200));
        int XIndex{0}, YIndex{2};


        skeleton_sprite.setTextureRect(sf::IntRect(XIndex *64 ,YIndex * 64,64,64));

        skeleton_sprite.scale(sf::Vector2f(2,2));
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
    playerSprite.setPosition(sf::Vector2f(0,0));

//----------------------------------------------------------------------------Load Player


    // ------------Calcule Direction of the bullet----------




    // ------------Calcule Direction of the bullet----------

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
            playerSprite.setPosition(position + sf::Vector2f(0.5f,0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            playerSprite.setPosition(position + sf::Vector2f(-0.5f,0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            playerSprite.setPosition(position + sf::Vector2f(0,-0.5f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::
            S)) {
            playerSprite.setPosition(position + sf::Vector2f(0,0.5f));
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(50,25)));
            int i = bullets.size()-1;
            bullets[i].setPosition(playerSprite.getPosition());

        }
        for (size_t i = 0; i < bullets.size(); i++) {
            sf::Vector2f BullerDirection = skeleton_sprite.getPosition() - bullets[i].getPosition();
            BullerDirection = normalizeVector(BullerDirection);
            bullets[i].setPosition(bullets[i].getPosition()+ BullerDirection * SpeedBullet );
        }


//------------------------------------------------------------------------Update


        //-------Draw-----
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.draw(skeleton_sprite);
        for (size_t i = 0; i < bullets.size(); i++) {
            window.draw(bullets[i]);
        }
        window.display();
        //-------Draw-----
    }

    return 0;
}