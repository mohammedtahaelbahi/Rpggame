#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

#ifndef RPGGAME_BULLET_H
#define RPGGAME_BULLET_H


class Bullet {

public :

private :
    sf::Vector2f direction;
    sf::RectangleShape rectangle_shape;
    float speed;


public:
    Bullet();
    ~Bullet();

    void Initialize(const sf::Vector2f& position,const sf::Vector2f& target, float Newspeed);
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    inline const sf::FloatRect GetGlobalBounds() {return rectangle_shape.getGlobalBounds();}
};


#endif //RPGGAME_BULLET_H