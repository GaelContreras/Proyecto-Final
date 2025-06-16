#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Brick.hpp"

class Level {
public:
    Level();
    void loadDefault();
    void draw(sf::RenderWindow& window) const;
    std::vector<Brick>& getBricks();

private:
    std::vector<Brick> bricks;
};

#endif