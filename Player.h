#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"

#ifndef RPGGAME_PLAYER_H
#define RPGGAME_PLAYER_H


class Player {
private:
    std::vector<sf::RectangleShape> bullets;
    float SpeedBullet;
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
    void Update(float deltaTime , Skeleton& skeleton);
    void Draw(sf::RenderWindow& window);
};


#endif //RPGGAME_PLAYER_H