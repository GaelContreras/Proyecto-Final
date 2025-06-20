#include "Paddle.hpp"

Paddle::Paddle(float x, float y, float width, float height)
    : speed(400.0f)
{
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(width / 2.0f, height / 2.0f);
}

void Paddle::move(float dx) {
    shape.move(dx, 0);
}

void Paddle::update(float dt, const sf::RenderWindow& window) {
    float dx = 0.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        dx -= speed * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        dx += speed * dt;

  
    sf::Vector2f pos = shape.getPosition();
    float halfWidth = shape.getSize().x / 2.0f;
    float nextX = pos.x + dx;
    if (nextX - halfWidth < 0) {
        dx = 0 - (pos.x - halfWidth);
    } else if (nextX + halfWidth > window.getSize().x) {
        dx = window.getSize().x - (pos.x + halfWidth);
    }

    move(dx);
}

void Paddle::draw(sf::RenderWindow& window) const {
    window.draw(shape); 
}

sf::FloatRect Paddle::getBounds() const {
    return shape.getGlobalBounds();
}

void Paddle::reset(float x, float y) {
    shape.setPosition(x, y);
}
