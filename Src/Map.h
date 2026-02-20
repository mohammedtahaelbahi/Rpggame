#pragma once
#include "Tile.h"

#include <SFML/Graphics.hpp>

#ifndef RPGGAME_MAP_H
#define RPGGAME_MAP_H


class Map {

private:
    sf::Texture TileSheetTexture;
    sf::Vector2i size;
    int TotalTilesX , TotalTilesY;
    Tile *tiles;
    int TotalTiles;
    static const int mapSize = 6;
    int mapWidth ;
    int mapHeight;
    int mapNumbers[mapSize] = {
        101,102,103,
        5,5,5
    };
    sf::Sprite mapSprite[mapSize];

public:
    Map();
    ~Map();
    void Initialize();
    void Load();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
};


#endif //RPGGAME_MAP_H