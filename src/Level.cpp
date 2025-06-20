#include "Level.hpp"

Level::Level() {
    loadDefault();
}

void Level::loadDefault() {
    bricks.clear();

    int rows = 5, cols = 10;
    float brickWidth = 60.f, brickHeight = 20.f, offsetX = 35.f, offsetY = 40.f;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c){
            float x = offsetX + c * (brickWidth + 8.f);
            float y = offsetY + r * (brickHeight + 8.f);
            sf::Color color = sf::Color(100 + 25*r, 50 + 30*r, 255 - 30*r);
            bricks.emplace_back(x, y, brickWidth, brickHeight, color);
        }
    }
}

void Level::draw(sf::RenderWindow& window) const {
    for (const auto& brick : bricks)
        if(!brick.isDestroyed())
            brick.draw(window);
}

std::vector<Brick>& Level::getBricks() {
    return bricks;
}