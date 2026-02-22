#include "Map.h"
#include <iostream>
Map::Map() : TotalTilesX(0) , TotalTilesY(0) , TotalTiles(0) ,tiles(nullptr) ,mapSprite(nullptr) {
}

Map::~Map() {
    delete [] mapSprite;
    delete [] tiles;

}

void Map::Initialize() {
}

void Map::Load() {


    mapLoader.Load("Assets/Maps/Level1.rmap",md);
    std::cerr << md.dataLength << std::endl;
    mapSprite = new sf::Sprite[md.dataLength];

    if (TileSheetTexture.loadFromFile(md.tilesheet)){

        TotalTilesX = TileSheetTexture.getSize().x / md.tileWidth ;
        TotalTilesY = TileSheetTexture.getSize().y/md.tileHeight;
        TotalTiles = TotalTilesX * TotalTilesY;
        tiles = new Tile[TotalTiles];

        for (int y = 0; y < TotalTilesY; y++) {
            for (int x = 0; x < TotalTilesX; x++) {
                int i = x + y * TotalTilesX;
                tiles[i].id = i;
                tiles[i].sprite.setTexture(TileSheetTexture);
                tiles[i].position= sf::Vector2i(x*md.tileWidth, y * md.tileHeight);
            }

        }
        std::cout <<"Prison Tilesheet loaded\n";
        for (int y = 0; y <md.mapHeight; y++) {
            for (int x = 0; x < md.mapWidth; x++) {
                int i = x+ y*md.mapWidth;
                int index = md.data[i];
                mapSprite[i].setTexture(TileSheetTexture);
                mapSprite[i].setTextureRect(sf::IntRect(tiles[index].position.x,
                    tiles[index].position.y,
                    md.tileWidth, md.tileHeight
                ));
                mapSprite[i].setScale(sf::Vector2f(md.scaleX,md.scaleY));
                mapSprite[i].setPosition(
                    sf::Vector2f(x*md.tileWidth*md.scaleX,
                    100+y*md.tileHeight*md.scaleY));

            }
        }
    }
    else {
        std::cout <<"Prison Tilesheet could not be loaded\n";
    }


}

void Map::Update(float deltaTime) {
}

void Map::Draw(sf::RenderWindow &window) {
    for(size_t i = 0; i < md.dataLength; i++){window.draw(mapSprite[i]);}
}
