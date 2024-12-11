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

#endif
