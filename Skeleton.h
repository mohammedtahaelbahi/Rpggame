#pragma once
#include <SFML/Graphics.hpp>
#ifndef RPGGAME_SKELETON_H
#define RPGGAME_SKELETON_H


class Skeleton {

private:
    sf::Texture texture;
sf::RectangleShape boundingRectangle;
    sf::Vector2i size;
public:
    sf::Sprite sprite;
    int health;
    sf::Text HealthText;
    sf::Font font;

public:
    Skeleton();
    ~Skeleton();
    void Initialize();
    void Load();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);

};


#endif //RPGGAME_SKELETON_H