#include "Player.h"
#include <iostream>
#include "Math.h"

Player::Player() :
 SpeedBullet (0.2f) , playerSpeed (2.0f) , FireRate(150.f), FireRateTimer(0){
}

Player::~Player() {
}

void Player::Initialize() {
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);
    size.x = 64; size.y = 64;


}

void Player::Load() {
    if(texture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
        sprite.setTexture(texture);
        int XIndex{3}, YIndex{3};


        std::cout <<"Image player loaded\n";
        sprite.setTextureRect(sf::IntRect(XIndex * size.x ,YIndex * size.y,size.x,size.y));
        sprite.scale(sf::Vector2f(2,2));
        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x,size.y * sprite.getScale().y));

    }
    else {
        std::cout <<"Image player texture could not be loaded\n";
    }
    sprite.setPosition(sf::Vector2f(0,0));

}

void Player::Update(float deltaTime,Skeleton& skeleton) {
    sf::Vector2f position = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sprite.setPosition(position + sf::Vector2f(0.5f,0)*playerSpeed*deltaTime);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        sprite.setPosition(position + sf::Vector2f(-0.5f,0)*playerSpeed*deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        sprite.setPosition(position + sf::Vector2f(0,-0.5f)*playerSpeed*deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::
        S)) {
        sprite.setPosition(position + sf::Vector2f(0,0.5f)*playerSpeed*deltaTime);
        }

    //----------------------------------------------------

    FireRateTimer += deltaTime;


    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && FireRateTimer > FireRate) {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(50,25)));
        int i = bullets.size()-1;
        bullets[i].setPosition(sprite.getPosition());
        FireRateTimer = 0;

    }
    for (size_t i = 0; i < bullets.size(); i++) {
        sf::FloatRect skeletonbounds = skeleton.sprite.getGlobalBounds();

        // Put the bullets in center of skeleton
        sf::Vector2f skeletoncenter{skeletonbounds.left+ skeletonbounds.width /2.0f , skeletonbounds.top +skeletonbounds.height/2.0f };
        sf::Vector2f BullerDirection = skeletoncenter - bullets[i].getPosition();
        BullerDirection = Math::normalizeVector(BullerDirection);
        // change the origin of bullets
        bullets[i].setOrigin(bullets[i].getSize()/2.0f);
        bullets[i].setPosition(bullets[i].getPosition()+ BullerDirection * SpeedBullet*deltaTime );

        if (Math::CheckRectCollision(bullets[i].getGlobalBounds(),skeleton.sprite.getGlobalBounds())) {
            bullets.erase(bullets.begin()+i);
            skeleton.health -=10;
            std::cout <<"Skeleton Health : " <<  skeleton.health << std::endl;


        }

    }

    //----------------------------------------------------

    boundingRectangle.setPosition(sprite.getPosition());

}

void Player::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(boundingRectangle);
    for (size_t i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i]);
    }
}
