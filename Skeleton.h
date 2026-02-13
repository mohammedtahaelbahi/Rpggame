#pragma once
#include <SFML/Graphics.hpp>
#ifndef RPGGAME_SKELETON_H
#define RPGGAME_SKELETON_H


class Skeleton {

private:
    sf::Texture texture;
public:
    sf::Sprite sprite;
public:
    void Initialize();
    void Load();
    void Update();
    void Draw(sf::RenderWindow& window);

};


#endif //RPGGAME_SKELETON_H