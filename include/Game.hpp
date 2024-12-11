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
    Platform platform;
    Obstacle obstacle;

    float gravity;
    float jumpStrength;
    float obstacleSpeed;
    bool isJumping;
};

Game::Game()
    : window(sf::VideoMode(1900, 1600), "Geometry Dash"),
      player(50.0f, 100.0f, 500.0f),
      platform(800.0f, 20.0f, 0.0f, 580.0f),
      obstacle(50.0f, 100.0f, 800.0f, 530.0f),
      gravity(0.5f), jumpStrength(-10.0f), obstacleSpeed(5.0f), isJumping(false) {
    window.setFramerateLimit(60);
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
    platform.move(obstacleSpeed);
    obstacle.move(obstacleSpeed);

    checkCollisions();

    if (platform.getBounds().left + platform.getBounds().width < 0.0f) {
        platform.reset(800.0f);
    }
    if (obstacle.getBounds().left + obstacle.getBounds().width < 0.0f) {
        obstacle.reset(800.0f);
    }
}

void Game::render() {
    window.clear();
    player.render(window);
    platform.render(window);
    obstacle.render(window);
    window.display();
}

void Game::checkCollisions() {
    if (player.getBounds().intersects(obstacle.getBounds())) {
        window.close(); // Terminar el juego
    }
}

#endif
