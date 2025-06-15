#ifndef BRICK_HPP
#define BRICK_HPP

#include <SFML/Graphics.hpp>

class Brick { 
public: 
    Brick(float x, float y, float Width, float height, sf::Color color); 
    void render(sf::RenderWindow& window) const; 
    sf::FloatRect getBounds() const; 
    bool isDestroyed() const; 
    void destroy(); 

private: 
    sf::RectangleShape shape; 
    bool destroyed; 
};

#endif
