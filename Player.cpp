#include "Player.h"
#include <iostream>
#include "Math.h"

void Player::Initialize() {

}

void Player::Load() {
    if(texture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
        sprite.setTexture(texture);
        int XIndex{0}, YIndex{3};


        std::cout <<"Image player loaded\n";
        sprite.setTextureRect(sf::IntRect(XIndex *64 ,YIndex * 64,64,64));

        sprite.scale(sf::Vector2f(2,2));
    }
    else {
        std::cout <<"Image player texture could not be loaded\n";
    }
    sprite.setPosition(sf::Vector2f(0,0));

}

void Player::Update(Skeleton& skeleton) {
    sf::Vector2f position = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sprite.setPosition(position + sf::Vector2f(0.5f,0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        sprite.setPosition(position + sf::Vector2f(-0.5f,0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        sprite.setPosition(position + sf::Vector2f(0,-0.5f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::
        S)) {
        sprite.setPosition(position + sf::Vector2f(0,0.5f));
        }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(50,25)));
        int i = bullets.size()-1;
        bullets[i].setPosition(sprite.getPosition());

    }
    for (size_t i = 0; i < bullets.size(); i++) {
        sf::Vector2f BullerDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
        BullerDirection = Math::normalizeVector(BullerDirection);
        bullets[i].setPosition(bullets[i].getPosition()+ BullerDirection * SpeedBullet );
    }
}

void Player::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
    for (size_t i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i]);
    }
}
