#include "Map.h"

Map::Map() : size(16,16){
}

Map::~Map() {
}

void Map::Initialize() {
    TotalTilesX = texture.getSize().x / size.x ; TotalTilesY = texture.getSize().y/size.y;
}

void Map::Load() {
    if (texture.loadFromFile("Assets/World/Prison/Prison.png")){
        std::cout <<"Prison Tilesheet loaded\n";
        for (size_t i = 0; i < 10; i++) {

                sprites[i].setTexture(texture);
                sprites[i].setTextureRect(sf::IntRect(i*size.x, 0 * size.y, size.x, size.y));
            sprites[i].setScale(sf::Vector2f(5,5));

                sprites[i].setPosition(sf::Vector2f(100+i*size.x*5,100));

        }
    }
    else {
        std::cout <<"Prison Tilesheet could not be loaded\n";
    }
}

void Map::Update(float deltaTime) {
}

void Map::Draw(sf::RenderWindow &window) {
    for(size_t i = 0; i < 10; i++){window.draw(sprites[i]);}
}
