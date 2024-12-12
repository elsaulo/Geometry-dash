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
    float getVelocityY() const;
    void setVelocityY(float newVelocityY);
    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);
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
    if (isJumping) {
        velocityY += gravity; // Aplicar gravedad solo si está saltando
    }

    shape.move(0, velocityY);

    if (shape.getPosition().y >= 950 - shape.getSize().y) {
        shape.setPosition(shape.getPosition().x, 950 - shape.getSize().y);
        isJumping = false;
        velocityY = 0;
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

float Player::getVelocityY() const {
    return velocityY;
}

void Player::setVelocityY(float newVelocityY) {
    velocityY = newVelocityY;
}

sf::Vector2f Player::getPosition() const {
    return shape.getPosition();
}

void Player::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

#endif
