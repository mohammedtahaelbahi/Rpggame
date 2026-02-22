#pragma once
#include <iostream>
#include "MapData.h"


#ifndef RPGGAME_MAPLOADER_H
#define RPGGAME_MAPLOADER_H


class MapLoader {
public:
    void Load(std::string filename,map_data& mapData);
};


#endif //RPGGAME_MAPLOADER_H