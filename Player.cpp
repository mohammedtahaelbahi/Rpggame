#include "Player.h"
#include <iostream>
#include "Math.h"

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
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(50,25)));
        int i = bullets.size()-1;
        bullets[i].setPosition(sprite.getPosition());


    }
    for (size_t i = 0; i < bullets.size(); i++) {
        sf::Vector2f BullerDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
        BullerDirection = Math::normalizeVector(BullerDirection);
        bullets[i].setPosition(bullets[i].getPosition()+ BullerDirection * SpeedBullet*deltaTime );
    }
    boundingRectangle.setPosition(sprite.getPosition());
   if (Math::CheckRectCollision(sprite.getGlobalBounds(),skeleton.sprite.getGlobalBounds())) {
       std::cout << "Tlas9na : )" << std::endl;
   }

}

void Player::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(boundingRectangle);
    for (size_t i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i]);
    }
}
