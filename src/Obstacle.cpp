#include "Obstacle.hpp"

Obstacle::Obstacle(float width, float height, float startX, float startY) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(startX, startY);
}

void Obstacle::move(float speed) {
    shape.move(-speed, 0);
}

void Obstacle::render(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Obstacle::getBounds() const {
    return shape.getGlobalBounds();
}

void Obstacle::reset(float startX) {
    shape.setPosition(startX, shape.getPosition().y);
}
