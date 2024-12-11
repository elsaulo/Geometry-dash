#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Platform.hpp"
#include "Obstacle.hpp"
#include <iostream>

int main() {
    // Configuración de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Geometry Dash");
    window.setFramerateLimit(60);

    // Crear instancias de objetos
    Player player(50.0f, 100.0f, 500.0f);       // Tamaño del bloque, posición inicial X e Y
    Platform platform(800.0f, 20.0f, 0.0f, 580.0f); // Ancho, alto, posición inicial X e Y
    Obstacle obstacle(50.0f, 50.0f, 800.0f, 530.0f); // Ancho, alto, posición inicial X e Y

    // Configuración de variables del juego
    const float gravity = 0.5f;       // Gravedad que afecta al jugador
    const float jumpStrength = -10.0f; // Fuerza del salto
    const float obstacleSpeed = 5.0f;  // Velocidad de movimiento de obstáculos
    bool isJumping = false;           // Estado del jugador (saltando o no)

    // Bucle principal del juego
    while (window.isOpen()) {
        // Procesar eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Detectar salto
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && !isJumping) {
                player.jump(jumpStrength);
                isJumping = true;
            }
        }

        // Actualizar lógica del juego
        player.update(gravity, isJumping);
        platform.move(obstacleSpeed);
        obstacle.move(obstacleSpeed);

        // Detectar colisiones
        if (player.getBounds().intersects(obstacle.getBounds())) {
            std::cout << "¡Colisión con el obstáculo!" << std::endl;
            window.close(); // Terminar el juego
        }

        // Resetear plataforma y obstáculo si salen de la pantalla
        if (platform.getBounds().left + platform.getBounds().width < 0.0f) {
            platform.reset(800.0f); // Reiniciar la posición de la plataforma
        }
        if (obstacle.getBounds().left + obstacle.getBounds().width < 0.0f) {
            obstacle.reset(800.0f); // Reiniciar la posición del obstáculo
        }

        // Renderizar objetos
        window.clear();
        player.render(window);
        platform.render(window);
        obstacle.render(window);
        window.display();
    }

    return 0;
}
