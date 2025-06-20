#include "Ball.hpp"

Ball::Ball(float x, float y, float radius)
    : shape(radius), speed(300.0f)
{
    shape.setPosition(x, y);
    shape.setOrigin(radius, radius);
    shape.setFillColor(sf::Color::White);
  
    velocity = sf::Vector2f(0.7f, -1.0f);
}

void Ball::update(float dt) {
    shape.move(velocity * speed * dt);
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
    velocity = sf::Vector2f(0.7f, -1.0f); 
}

sf::Vector2f Ball::getVelocity() const { 
    return velocity;
}
