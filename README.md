# Proyecto-Final

## Descripción

**Breakout SFML** es un clon simple del clásico juego Breakout, desarrollado en C++ utilizando la biblioteca gráfica SFML. El objetivo es controlar una paleta para hacer rebotar una bola y destruir todos los ladrillos del nivel sin dejar que la bola caiga fuera de la pantalla.

## Capturas 

![Estructura de clases](docs/Estructura%20de%20clases.PNG)

![Inicio del juego](docs/Breakout%201.PNG)

![Juego en acción](docs/Breakout%202.PNG)

## Compilación y Ejecución

### Requisitos 

- C++17
- [SFML 2.5.x o superior](https://www.sfml-dev.org/download.php)
- MinGW (Windows)

## Diagrama UML

@startuml 

class Game {
  - window: sf::RenderWindow
  - paddle: Paddle
  - ball: Ball
  - level: Level
  - windowWidth: unsigned int
  - windowHeight: unsigned int
  + run()
  + processEvents()
  + update(dt: float)
  + render()
  + handleCollisions()
  + reset()
}

class Paddle {
  - shape: sf::RectangleShape
  - speed: float
  + Paddle(x: float, y: float, width: float, height: float)
  + move(dx: float)
  + update(dt: float, window: const sf::RenderWindow &)
  + draw(window: sf::RenderWindow &) const
  + getBounds() const
  + reset(x: float, y: float)
}

class Ball {
  - shape: sf::CircleShape
  - velocity: sf::Vector2f
  - speed: float
  + Ball(x: float, y: float, radius: float)
  + update(dt: float)
  + draw(window: sf::RenderWindow &) const
  + getBounds() const
  + setPosition(x: float, y: float)
  + invertVelocityX()
  + invertVelocityY()
  + reset(x: float, y: float)
  + getVelocity() const
}

class Brick {
  - shape: sf::RectangleShape
  - destroyed: bool
  + Brick(x: float, y: float, width: float, height: float)
  + draw(window: sf::RenderWindow &) const
  + getBounds() const
  + destroy()
  + isDestroyed() const
}

class Level {
  - bricks: std::vector<Brick>
  + loadDefault()
  + getBricks(): std::vector<Brick>&
  + draw(window: sf::RenderWindow &) const
}

Game "1" o-- "1" Paddle
Game "1" o-- "1" Ball
Game "1" o-- "1" Level
Level "1" *-- "1..*" Brick

@enduml

### Compilar

- make

### Ejecutar

- ./bin/breakout.exe

## Manual de Usuario 
1. Usa las flechas izquierda/derecha para mover la paleta. 
2. Rebota la bola contra la paleta y elimina todos los ladrillos del nivel. 
3. Si la bola cae fuera de la ventana, el juego se reinicia. 
4. ¡Intenta destruir todos los ladrillos! 

## Creditos y Licencia 

- Desarrollado por:

- Alex-24110229
- GaelContreras

- Basado en el clásico Breakout

- Uso educativo. SFML está bajo licencia Zlib.