#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <SFML/Graphics.hpp>

class Platform {
public:
    Platform(float width, float height, float startX, float startY);
    void move(float speed);
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    void reset(float startX);

private:
    sf::RectangleShape shape;
};
Platform::Platform(float width, float height, float startX, float startY) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(startX, startY);
}

void Platform::move(float speed) {
    shape.move(-speed, 0);
}

void Platform::render(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Platform::getBounds() const {
    return shape.getGlobalBounds();
}

void Platform::reset(float startX) {
    shape.setPosition(startX, shape.getPosition().y);
}

#endif
