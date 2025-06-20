#include "Game.hpp"

Game::Game(unsigned int width, unsigned int height)
    : window(sf::VideoMode(width, height), "Breakout"), 
      paddle(width / 2.0f, height - 30.0f, 100.0f, 20.0f),
      ball(width / 2.0f, height / 2.0f, 10.0f),
      windowWidth(width), windowHeight(height)
{
  
    level.loadDefault(); 
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        
    }
}

void Game::update(float dt) {
    // Actualizar paddle según entrada del usuario
    paddle.update(dt, window);

  
    ball.update(dt);

    // Revisar colisiones
    handleCollisions();
}

void Game::handleCollisions() {
    // 1. Rebote con paredes laterales
    if (ball.getBounds().left <= 0 || 
        ball.getBounds().left + ball.getBounds().width >= windowWidth) {
        ball.invertVelocityX();
    }

    
    if (ball.getBounds().top <= 0) {
        ball.invertVelocityY();
    }

    
    if (ball.getBounds().top + ball.getBounds().height >= windowHeight) {
        reset();
        return;
    }

   
    if (ball.getBounds().intersects(paddle.getBounds())) {
        // Rebote sólo si viene hacia abajo
        if (ball.getVelocity().y > 0)
            ball.invertVelocityY();
    }

   
    for (auto& brick : level.getBricks()) {
        if (!brick.isDestroyed() && ball.getBounds().intersects(brick.getBounds())) {
            brick.destroy();
            ball.invertVelocityY(); 
            break; 
        }
    }
}

void Game::reset() {
  
    paddle.reset(windowWidth / 2.0f, windowHeight - 30.0f);
    ball.reset(windowWidth / 2.0f, windowHeight / 2.0f);

  
    level.loadDefault();
}

void Game::render() {
    window.clear(sf::Color::Black);
    paddle.draw(window);
    ball.draw(window);
    level.draw(window);
    window.display();
}
