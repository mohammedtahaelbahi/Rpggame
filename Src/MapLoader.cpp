#include "MapLoader.h"
#include <fstream>
#include <string>


void MapLoader::Load(std::string filename , map_data& mapData) {
    std::string line;
    std::ifstream file(filename);
    bool isMapValid = false;
    if (file.is_open()) {
        while (std::getline(file,line)) {

            if (!isMapValid) {
                if (line == "[Map]") {
                    isMapValid = true;
                    continue;
                }
                else {
                    std::cout<< "rmap file is not valid" << std::endl;
                    break;
            }

            }
            if (isMapValid) {

                int count = line.find('=');
                std::string variable = line.substr(0, count);
                std::string value = line.substr(count + 1,line.length()-count);



try {
    if (variable == "version") {
        mapData.version = std::stoi(value);
    }
    if (variable == "tilesheet") {
        mapData.tilesheet = value;
    }
    else if (variable == "name") {
        mapData.name = value;
    }
    else if (variable == "tileWidth") {
        mapData.tileWidth = std::stoi(value);
    }
    else if (variable == "tileHeight") {
        mapData.tileHeight = std::stoi(value);
    }
    else if (variable == "mapWidth") {
        mapData.mapWidth = std::stoi(value);
    }
    else if (variable == "mapHeight") {
        mapData.mapHeight = std::stoi(value);
    }
    else if (variable == "scaleX") {
        mapData.scaleX = std::stoi(value);
    }
    else if (variable == "scaleY") {
        mapData.scaleY = std::stoi(value);
    }
    else if (variable == "dataLength") {
        mapData.dataLength = std::stoi(value);
    }
    else if (variable == "data") {

std::cout<< "MAMAMIYAAA !!!!" << std::endl;
        mapData.data = new int[mapData.dataLength];
        int offset = 0;
        int i =0;
        while (true) {
            int count = value.find(',',offset);
            std::string mapIndex = value.substr(offset,count-offset);
            if (mapIndex == ";") {
                break;
            }
            mapData.data[i] = std::stoi(mapIndex);
            offset = count+1;
            i++;
        }
    }
}
                catch (std::exception& e) {
                    std::cout<< "There's an Error , 3awd dir khdmtk !" << std::endl;
                }


            }



        }
        file.close();
    }
    else {
        std::cout<< "Unable to open file";
    }
}
