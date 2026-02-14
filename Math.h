#pragma once
#include <SFML/Graphics.hpp>

#ifndef RPGGAME_MATH_H
#define RPGGAME_MATH_H


class Math {
public:
  static  sf::Vector2f normalizeVector(sf::Vector2f v);
  static bool CheckRectCollision(sf::FloatRect rect1 , sf::FloatRect rect2);
};


#endif //RPGGAME_MATH_H