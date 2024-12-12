#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Platform.hpp"
#include "Obstacle.hpp"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void checkCollisions();

    sf::RenderWindow window;
    Player player;
    std::vector<Platform> platforms;
    std::vector<Obstacle> obstacles;

    float gravity;
    float jumpStrength;
    float obstacleSpeed;
    bool isJumping;
    sf::Vector2f playerInitialPosition; // Posición inicial del jugador
};

Game::Game()
    : window(sf::VideoMode(1000, 1000), "Geometry Dash"),
      player(50.0f, 100.0f, 950.0f), // Inicializar el jugador en la parte inferior de la ventana
      gravity(0.4f), jumpStrength(-10.0f), obstacleSpeed(5.0f), isJumping(false),
      playerInitialPosition(player.getPosition()) // Guardar posición inicial del jugador
{
    window.setFramerateLimit(60);

    // Inicializar plataformas
    platforms = {
        {300.0f, 20.0f, 800.0f, 850.0f},
        {200.0f, 20.0f, 1500.0f, 850.0f},
        {300.0f, 20.0f, 2700.0f, 850.0f},
        {200.0f, 20.0f, 3400.0f, 850.0f},
    };

    // Inicializar obstáculos
    obstacles = {
        {50.0f, 100.0f, 600.0f, 900.0f},
        {50.0f, 200.0f, 1100.0f, 800.0f},
        {50.0f, 200.0f, 1700.0f, 800.0f},
        {170.0f, 100.0f, 1700.0f, 900.0f},
        {50.0f, 100.f, 2000.0f, 900.0f},
        {50.0f, 100.0f, 2200.0f, 800.0f},
        {50.0f, 100.0f, 2500.0f, 900.0f},
        {50.0f, 200.0f, 3000.0f, 800.0f},
        {50.0f, 200.0f, 3600.0f, 800.0f},
        {170.0f, 100.0f, 3600.0f, 900.0f},
        {50.0f, 100.f, 3900.0f, 900.0f},
        {50.0f, 100.0f, 4100.0f, 800.0f},
    };
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && !isJumping) {
            player.jump(jumpStrength);
            isJumping = true;
        }
    }
}

void Game::update() {
    player.update(gravity, isJumping);

    // Mover plataformas y reiniciar cuando estén fuera de la pantalla
    for (size_t i = 0; i < platforms.size(); ++i) {
        platforms[i].move(obstacleSpeed);

        if (platforms[i].getBounds().left + platforms[i].getBounds().width < 0.0f) {
            float newX = (i == 0 ? platforms.back().getBounds().left + platforms.back().getBounds().width + 200.0f
                                 : platforms[i - 1].getBounds().left + platforms[i - 1].getBounds().width + 200.0f);
            platforms[i].reset(newX);
        }
    }

    // Mover obstáculos y reiniciar cuando estén fuera de la pantalla
    for (size_t i = 0; i < obstacles.size(); ++i) {
        obstacles[i].move(obstacleSpeed);

        if (obstacles[i].getBounds().left + obstacles[i].getBounds().width < 0.0f) {
            float newX = (i == 0 ? obstacles.back().getBounds().left + obstacles.back().getBounds().width + 300.0f
                                 : obstacles[i - 1].getBounds().left + obstacles[i - 1].getBounds().width + 300.0f);
            obstacles[i].reset(newX);
        }
    }

    checkCollisions();

    // Verificar si el jugador cae por debajo de la pantalla
    if (player.getPosition().y > window.getSize().y) {
        // Reiniciar la posición del jugador y sus atributos
        player.setPosition(playerInitialPosition.x, playerInitialPosition.y);
        player.setVelocityY(0); // Detener cualquier velocidad vertical
        isJumping = false;
    }
}

void Game::render() {
    window.clear();
    player.render(window);
    for (auto& platform : platforms) platform.render(window);
    for (auto& obstacle : obstacles) obstacle.render(window);
    window.display();
}

void Game::checkCollisions() {
    sf::FloatRect playerBounds = player.getBounds();

    for (auto& platform : platforms) {
        sf::FloatRect platformBounds = platform.getBounds();
        if (playerBounds.intersects(platformBounds) &&
            playerBounds.top + playerBounds.height - player.getVelocityY() < platformBounds.top) {
            player.setPosition(player.getPosition().x, platformBounds.top - playerBounds.height);
            isJumping = false;
            player.setVelocityY(0);
        }
    }

    for (const auto& obstacle : obstacles) {
        if (playerBounds.intersects(obstacle.getBounds())) {
            window.close();
        }
    }
}

#endif
