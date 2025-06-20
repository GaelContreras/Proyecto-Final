#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

class Paddle {
public:
    Paddle(float x, float y, float width, float height);
    void move(float dx);
    void update(float dt, const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) const; 
    sf::FloatRect getBounds() const;
    void reset(float x, float y);

private:
    sf::RectangleShape shape;
    float speed;
};

#endif
