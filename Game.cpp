#include "Game.hpp"

Game::Game(unsigned int width, unsigned int height)
    : window(sf::VideoMode(width, height), "Breakout"),
      paddle(width / 2.0f, height - 30.0f, 100.0f, 20.0f),
      ball(width / 2.0f, height / 2.0f, 10.0f),
      windowWidth(width), windowHeight(height)
{

}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        float dt = clock.restar().asSeconds();
        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window.close()

    }
}

void Game::update(float dt) {

}

void Game::render() {
    window.clear(sf::Color::Black);
    paddle.draw(window);
    ball.draw(window);
    level.draw(window);
    window.display();
}

void Game::handleCollisions() {

}

void Game::reset() {
    
}