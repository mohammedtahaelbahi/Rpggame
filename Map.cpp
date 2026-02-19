#include "Map.h"
#include <iostream>
Map::Map() : size(16,16), TotalTilesX(0) , TotalTilesY(0) , TotalTiles(0) {
}

Map::~Map() {
}

void Map::Initialize() {
}

void Map::Load() {
    if (TileSheetTexture.loadFromFile("Assets/World/Prison/Prison.png")){

        TotalTilesX = TileSheetTexture.getSize().x / size.x ;
        TotalTilesY = TileSheetTexture.getSize().y/size.y;
        std::cerr << TotalTilesX << " " << TotalTilesY << "\n";
        TotalTiles = TotalTilesX * TotalTilesY;
        tiles = new Tile[TotalTiles];

        for (int y = 0; y < TotalTilesY; y++) {
            for (int x = 0; x < TotalTilesX; x++) {
                int i = x + y * TotalTilesX;
                tiles[i].id = i;
                tiles[i].sprite.setTexture(TileSheetTexture);
                tiles[i].position= sf::Vector2i(x*size.x, y * size.y);
            }

        }
        std::cout <<"Prison Tilesheet loaded\n";
    }
    else {
        std::cout <<"Prison Tilesheet could not be loaded\n";
    }

    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 3; x++) {
            int i = x+ y*3;
            int index = mapNumbers[i];
            mapSprite[i].setTexture(TileSheetTexture);
            mapSprite[i].setTextureRect(sf::IntRect(tiles[index].position.x,
                tiles[index].position.y,
                size.x, size.y
            ));
            mapSprite[i].setScale(sf::Vector2f(5,5));
            mapSprite[i].setPosition(sf::Vector2f(x*16*5, 100+y*16*5));

        }
    }
}

void Map::Update(float deltaTime) {
}

void Map::Draw(sf::RenderWindow &window) {
    for(size_t i = 0; i < 6; i++){window.draw(mapSprite[i]);}
}
