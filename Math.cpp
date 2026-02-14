//
// Created by elbahi on 13‏/2‏/2026.
//

#include "Math.h"
#include <math.h>
sf::Vector2f Math::normalizeVector(sf::Vector2f v) {

    float m = std::sqrt(v.x * v.x + v.y * v.y);
    sf::Vector2f normalizedvector;
    normalizedvector.x = v.x / m;
    normalizedvector.y = v.y / m;
    return normalizedvector;
}
bool Math::CheckRectCollision(sf::FloatRect rect1, sf::FloatRect rect2) {
    if (rect1.left + rect1.width > rect2.left &&
        rect2.left + rect2.width > rect1.left &&
        rect2.top + rect2.height > rect1.top &&
        rect1.top + rect1.height > rect2.top)
        return true;
    return false;
}
