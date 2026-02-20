#pragma once

#include <SFML/Graphics.hpp>
#ifndef RPGGAME_FRAMERATE_H
#define RPGGAME_FRAMERATE_H


class FrameRate {
private:
    sf::Text FrameRateText;
    sf::Font font;
    int time ;
public:
    FrameRate();
    ~FrameRate();
    void Initialize();
    void Load();
    void Update(float deltatime);
    void Draw(sf::RenderWindow &window);
};


#endif //RPGGAME_FRAMERATE_H