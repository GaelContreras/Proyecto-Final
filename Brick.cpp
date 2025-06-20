#include "Brick.hpp"

#include "Brick.hpp"

Brick::Brick(float x, float y, float width, float height, sf::Color color)
    : destroyed(false)
{
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(color);
    shape.setOrigin(width / 2.0f, height / 2.0f);
}

void Brick::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::FloatRect Brick::getBounds() const {
    return shape.getGlobalBounds();
}

bool Brick::isDestroyed() const {
    return destroyed;
}

void Brick::destroy() {
    destroyed = true;
}
