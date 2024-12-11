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

#endif
