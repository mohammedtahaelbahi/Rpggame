#include "Bullet.h"

Bullet::Bullet() : speed(0) {
}

Bullet::~Bullet() {
}

void Bullet::Initialize(const sf::Vector2f& position,const sf::Vector2f& target, float Newspeed) {
    this->speed = Newspeed;
    rectangle_shape.setSize(sf::Vector2f(50,25));
    rectangle_shape.setPosition(position);
    direction = Math::normalizeVector(target-position);
}

void Bullet::Update(float deltaTime) {
    rectangle_shape.setPosition(rectangle_shape.getPosition() + direction * speed * deltaTime);
}

void Bullet::Draw(sf::RenderWindow &window) {
    window.draw(rectangle_shape);
}
