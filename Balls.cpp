#include "Ball.hpp"

Ball::Ball(float x, float y, float radius)
    : speed(300.0f)
{
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(radius, radius);
    setPosition(x, y);
    velocity = {speed, -speed};
}

void Ball::update(float dt) {
    shape.move(velocity * dt);
}

void Ball::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::FloatRect Ball::getBounds() const {
    return shape.getGlobalBounds();
}

void Ball::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

void Ball::invertVelocityX() {
    velocity.x = -velocity.x;
}

void Ball::invertVelocityY() {
    velocity.y = -velocity.y;
}

void Ball::reset(float x, float y) {
    setPosition(x, y);
    velocity = {speed, -speed};
}