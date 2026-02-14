#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize() {
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
    boundingRectangle.setOutlineThickness(1);
    size.x = 64; size.y = 64;
}

void Skeleton::Load() {
    if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")){
        std::cout <<"Image enemy loaded\n";
        sprite.setTexture(texture);
        int XIndex{0}, YIndex{2};


        sprite.setTextureRect(sf::IntRect(XIndex * size.x ,YIndex * size.y,size.x,size.y));

        sprite.scale(sf::Vector2f(2,2));
        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x,size.y * sprite.getScale().y));
    }
    else {
        std::cout <<"Image enemy texture could not be loaded\n";
    }
    sprite.setPosition(sf::Vector2f(600,400));

}

void Skeleton::Update(float deltaTime) {
    boundingRectangle.setPosition(sprite.getPosition());
}

void Skeleton::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(boundingRectangle);
}
