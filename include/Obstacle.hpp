#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <SFML/Graphics.hpp>

class Obstacle {
public:
    Obstacle(float width, float height, float startX, float startY);
    void move(float speed);
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    void reset(float startX);
private:
    sf::RectangleShape shape;
};

Obstacle::Obstacle(float width, float height, float startX, float startY) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(startX, startY);
}

void Obstacle::move(float speed) {
    shape.move(-speed, 0.0f);
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

#endif
