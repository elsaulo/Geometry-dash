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

#endif
