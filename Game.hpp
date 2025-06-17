#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Level.hpp"

class Game {
public:
    Game(unsigned int width, unsigned int height);
    void run();

private:
    void processEvents();
    void update(float dt);
    void render();
    void handleCollisions();
    void reset();

    sf::RenderWindow window;
    Paddle paddle;
    Ball ball;
    Level level;
    unsigned int windowWidth;
    unsigned int windowHeight;
};

#endif