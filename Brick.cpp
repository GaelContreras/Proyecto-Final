#include "Brick.hpp"

Brick::Brick(float x, float y, float width, float height, sf::Color color)
    :destroyed(false)
{
    shape.setPosition(x, y);
    shape.setSize({width, height});
    shape.setFillColor(color);
    shape.setOrigin(width / 2.0f, height / 2.0f);
}

void Brick::render(sf::Renderwindow& window) const{
    window.draw(shape);
}

sf::FloatRect Brick::getRoundRect() const {
    return shape.getGlobal Bounds();
}

bool Brick::isDestroyed() const {
    return destroyed;
}

void Brick::destroy() {
    destroyed = true;
}
