#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float BLOCK_SIZE = 50.0f;
const float PLATFORM_WIDTH = 150.0f;
const float PLATFORM_HEIGHT = 20.0f;
const float OBSTACLE_WIDTH = 50.0f;
const float OBSTACLE_HEIGHT = 100.0f;
const float GRAVITY = .3f;
const float JUMP_STRENGTH = -10.0f;

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Geometry Dash Clone");
    window.setFramerateLimit(60);

    // Player block
    sf::RectangleShape player(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
    player.setFillColor(sf::Color::Blue);
    player.setPosition(100, WINDOW_HEIGHT - BLOCK_SIZE);

    // Obstacles (Level design)
    std::vector<sf::RectangleShape> obstacles;
    for (int i = 0; i < 5; ++i) {
        sf::RectangleShape obstacle(sf::Vector2f(OBSTACLE_WIDTH, OBSTACLE_HEIGHT));
        obstacle.setFillColor(sf::Color::Red);
        obstacle.setPosition(WINDOW_WIDTH + i * 400, WINDOW_HEIGHT - OBSTACLE_HEIGHT);
        obstacles.push_back(obstacle);
    }

    // Platforms (Level design)
    std::vector<sf::RectangleShape> platforms;
    for (int i = 0; i < 3; ++i) {
        sf::RectangleShape platform(sf::Vector2f(PLATFORM_WIDTH, PLATFORM_HEIGHT));
        platform.setFillColor(sf::Color::Green);
        platform.setPosition(WINDOW_WIDTH + i * 600, WINDOW_HEIGHT - 150 - i * 100);
        platforms.push_back(platform);
    }

    float playerVelocityY = 0.0f;
    bool isJumping = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && !isJumping) {
                playerVelocityY = JUMP_STRENGTH;
                isJumping = true;
            }
        }

        // Gravity
        playerVelocityY += GRAVITY;
        player.move(0, playerVelocityY);

        // Ground collision
        if (player.getPosition().y >= WINDOW_HEIGHT - BLOCK_SIZE) {
            player.setPosition(player.getPosition().x, WINDOW_HEIGHT - BLOCK_SIZE);
            playerVelocityY = 0;
            isJumping = false;
        }

        // Platform collision
        for (auto& platform : platforms) {
            if (player.getGlobalBounds().intersects(platform.getGlobalBounds()) && playerVelocityY > 0) {
                player.setPosition(player.getPosition().x, platform.getPosition().y - BLOCK_SIZE);
                playerVelocityY = 0;
                isJumping = false;
            }
        }

        // Move obstacles
        for (auto& obstacle : obstacles) {
            obstacle.move(-5.0f, 0);
            if (obstacle.getPosition().x + OBSTACLE_WIDTH < 0) {
                obstacle.setPosition(WINDOW_WIDTH + (obstacles.size() - 1) * 400, WINDOW_HEIGHT - OBSTACLE_HEIGHT);
            }
        }

        // Move platforms
        for (auto& platform : platforms) {
            platform.move(-5.0f, 0);
            if (platform.getPosition().x + PLATFORM_WIDTH < 0) {
                platform.setPosition(WINDOW_WIDTH + (platforms.size() - 1) * 600, platform.getPosition().y);
            }
        }

        // Collision detection with obstacles
        for (const auto& obstacle : obstacles) {
            if (player.getGlobalBounds().intersects(obstacle.getGlobalBounds())) {
                std::cout << "Game Over!" << std::endl;
                window.close();
            }
        }

        // Render
        window.clear(sf::Color::White);
        window.draw(player);
        for (const auto& obstacle : obstacles) {
            window.draw(obstacle);
        }
        for (const auto& platform : platforms) {
            window.draw(platform);
        }
        window.display();
    }

    return 0;
}
