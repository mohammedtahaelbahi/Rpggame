#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include "Bullet.h"
#ifndef RPGGAME_PLAYER_H
#define RPGGAME_PLAYER_H


class Player {
private:
    std::vector<Bullet> bullets;
    float FireRate;
    float FireRateTimer;
    float playerSpeed;
    sf::Texture texture;
    sf::RectangleShape boundingRectangle;
    sf::Vector2i size;

public:
    sf::Sprite sprite;
public:
    Player();
    ~Player();
    void Initialize();
    void Load();
    void Update(float deltaTime , Skeleton& skeleton,sf::Vector2f& mousePosition);
    void Draw(sf::RenderWindow& window);
};


#endif //RPGGAME_PLAYER_H