#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(float blockSize, float startX, float startY);
    void update(float gravity, bool& isJumping);
    void jump(float jumpStrength);
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
private:
    sf::RectangleShape shape;
    float velocityY;
};
Player::Player(float blockSize, float startX, float startY) : velocityY(0.0f) {
    shape.setSize(sf::Vector2f(blockSize, blockSize));
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(startX, startY);
}

void Player::update(float gravity, bool& isJumping) {
    velocityY += gravity;
    shape.move(0, velocityY);

    if (shape.getPosition().y >= 600 - shape.getSize().y) {
        shape.setPosition(shape.getPosition().x, 600 - shape.getSize().y);
        velocityY = 0;
        isJumping = false;
    }
}

void Player::jump(float jumpStrength) {
    velocityY = jumpStrength;
}

void Player::render(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Player::getBounds() const {
    return shape.getGlobalBounds();
}

#endif
