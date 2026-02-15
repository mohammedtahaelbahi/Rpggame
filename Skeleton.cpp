#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton() : health(100) {
}

Skeleton::~Skeleton() {
}

void Skeleton::Initialize() {
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
    boundingRectangle.setOutlineThickness(1);
    size.x = 64; size.y = 64;
}

void Skeleton::Load() {

    if (font.loadFromFile("Assets/Fonts/ArialCE.ttf")) {
        std::cout<<"Font loaded ArialCE.ttf from Assets"<<std::endl;
        HealthText.setFont(font);
    }
    else {
        std::cout<<"Font not loaded from Assets"<<std::endl;
    }




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
    HealthText.setPosition(sprite.getPosition());

}

void Skeleton::Update(float deltaTime) {
    boundingRectangle.setPosition(sprite.getPosition());
    HealthText.setString(std::to_string(health));
    HealthText.setPosition(sprite.getPosition());

}

void Skeleton::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(boundingRectangle);
    window.draw(HealthText);
}
