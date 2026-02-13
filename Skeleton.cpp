#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize() {
}

void Skeleton::Load() {
    if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")){
        std::cout <<"Image enemy loaded\n";
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(600,400));
        int XIndex{0}, YIndex{2};


        sprite.setTextureRect(sf::IntRect(XIndex *64 ,YIndex * 64,64,64));

        sprite.scale(sf::Vector2f(2,2));
    }
    else {
        std::cout <<"Image enemy texture could not be loaded\n";
    }
}

void Skeleton::Update() {
}

void Skeleton::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
