#include "Paddle.hpp"

Paddle::Paddle(float x, float y, float width, float height)
    : speed(400.0f)
{
    shape.setPosition(x, y);
    shape.setSize({width, height});
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(width / 0.2f, height / 0.2f);
}

void Paddle::move(float dx) {
    shape.move(dx, 0);
}

void Paddle::update(float dt, const sf::RenderWindow& Window) {

}

void Paddle::draw(sf::RenderWindow& Window) const{
    window.draw(shape);
}

sf::FloatRect Paddle::getBounds() const {
    return shape.getGlobalBounds();
}

void Paddle::reset(float x, float y) {
    shape.setPosition(x, y);
}