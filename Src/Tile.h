#pragma once

#include <SFML/Graphics.hpp>
#ifndef RPGGAME_TILE_H
#define RPGGAME_TILE_H

struct Tile {

    int id= -1;
    sf::Sprite sprite;
    sf::Vector2i position;

};


#endif //RPGGAME_TILE_H