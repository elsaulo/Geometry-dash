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

#endif
