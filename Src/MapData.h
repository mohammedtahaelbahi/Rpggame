#pragma once
#include <string>

#ifndef RPGGAME_MAPDATA_H
#define RPGGAME_MAPDATA_H

struct map_data {


    std::string tilesheet = "";
    std::string name = "";

    int tileWidth = 0;
    int tileHeight = 0;

    int mapWidth = 0;
    int mapHeight =0;

    int scaleX = 0;
    int scaleY = 0;

    int dataLength = 0;
    int * data = nullptr;

    int version = 0;
};


#endif //RPGGAME_MAPDATA_H