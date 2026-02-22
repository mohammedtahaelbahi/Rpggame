#pragma once
#include "Tile.h"
#include "MapLoader.h"
#include <SFML/Graphics.hpp>

#ifndef RPGGAME_MAP_H
#define RPGGAME_MAP_H


class Map {

private:

    map_data md; //mapdata = md
    MapLoader mapLoader;




    sf::Texture TileSheetTexture;
    int TotalTilesX , TotalTilesY;
    Tile *tiles;
    int TotalTiles;


    sf::Sprite *mapSprite;

public:
    Map();
    ~Map();
    void Initialize();
    void Load(std::string filename);
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
};


#endif //RPGGAME_MAP_H