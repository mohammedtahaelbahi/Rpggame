#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef RPGGAME_MAP_H
#define RPGGAME_MAP_H


class Map {

private:
    sf::Texture texture;
    sf::Sprite sprites[10];
    sf::Vector2i size;
    int TotalTilesX , TotalTilesY;


public:
    Map();
    ~Map();
    void Initialize();
    void Load();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
};


#endif //RPGGAME_MAP_H