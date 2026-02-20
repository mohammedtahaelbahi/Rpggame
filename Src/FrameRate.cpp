#include "FrameRate.h"
#include <iostream>

FrameRate::FrameRate() : time(0) {
}

FrameRate::~FrameRate() {
}

void FrameRate::Initialize() {
}

void FrameRate::Load() {
    if (font.loadFromFile("Assets/Fonts/ArialCE.ttf")) {
        std::cout<<"Font loaded ArialCE.ttf from Assets"<<std::endl;
        FrameRateText.setFont(font);
    }
    else {
        std::cout<<"Font not loaded from Assets"<<std::endl;
    }
}

void FrameRate::Update(float deltaTime) {
     time += deltaTime;
    if (time >= 100.0) {
        int fps = 1000.0 / deltaTime;
        FrameRateText.setString("Fps : " + std::to_string(fps) + " and FrameTime : " + std::to_string(int(deltaTime)));
        time = 0;
    }


}

void FrameRate::Draw(sf::RenderWindow &window) {
    window.draw(FrameRateText);
}


