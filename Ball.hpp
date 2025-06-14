#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball {
public: 
    Ball(float x, float y, float radius);
    void update(float dt);
    void draw(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;
    void setPosition(float x, float y);
    void invertVelocityX();
    void invertVelocityY();
    void reset(float x, float y);

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float speed;
};
