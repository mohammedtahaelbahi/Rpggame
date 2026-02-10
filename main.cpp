#include <SFML/Graphics.hpp>

int main() {
    // ------ Initiale-------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800,600), "Rpg Game",sf::Style::Default,settings);

    sf::CircleShape cir(50.f);
    cir.setFillColor(sf::Color::White);
    //cir.setOutlineThickness(10.f);

    //cir.setOutlineColor(sf::Color::Blue);
    cir.setOrigin(sf::Vector2f(50.f,50.f));
    cir.setPosition(50.f,50.f);




    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(cir);
        window.display();
    }

    return 0;
}
