# Juego Geometry dash
# Instructivo para el Proyecto Geometry Dash

## Introducción
Este proyecto es una implementación simple de un juego estilo **Geometry Dash** utilizando **SFML (Simple and Fast Multimedia Library)**. El proyecto incluye clases principales para manejar el jugador, las plataformas, los obstáculos y un fondo visual.

## Requisitos Previos
Antes de compilar y ejecutar el proyecto, asegúrate de tener instalado lo siguiente:

1. **SFML**: Asegúrate de tener SFML instalado en tu sistema. Puedes descargarlo desde [SFML](https://www.sfml-dev.org/).
2. **Compilador C++**: Necesitarás un compilador compatible con C++11 o superior (por ejemplo, g++, clang++ o MSVC).
3. **CMake (opcional)**: Si usas CMake para construir el proyecto.

## Estructura del Proyecto
La estructura del proyecto es la siguiente:

```
/project-directory
    /assets
        background.png       # Imagen utilizada como fondo
        /images
        /music
        /sounds
    /include
        Background.hpp       # Clase para manejar el fondo
        Game.hpp             # Clase principal del juego
        Player.hpp           # Clase para el jugador
        Platform.hpp         # Clase para las plataformas
        Obstacle.hpp         # Clase para los obstáculos
    /src
        main.cpp             # Archivo principal del programa
    makefile                 # Script de compilación
    README.md                # Descripción del proyecto
```

## Instalación y Configuración
### Paso 1: Descargar el Proyecto
Descarga y extrae el proyecto desde el archivo ZIP proporcionado.

### Paso 2: Compilar el Proyecto
#### Usando Makefile:
1. Abre una terminal en el directorio raíz del proyecto.
2. Ejecuta el siguiente comando:
   ```
   make
   ```
3. Esto generará un ejecutable en el directorio `bin`.

#### Usando CMake (opcional):
Si prefieres usar CMake:
1. Crea un directorio de compilación:
   ```
   mkdir build && cd build
   ```
2. Ejecuta CMake:
   ```
   cmake ..
   ```
3. Compila el proyecto:
   ```
   cmake --build .
   ```

### Paso 3: Ejecutar el Juego
Ejecuta el binario generado. Por ejemplo:
```
./bin/Geometry-dash
```

## Controles del Juego
- **Espacio**: Hacer saltar al jugador.
- **Enter**: Iniciar o reiniciar el juego.

## Clases Principales
### 1. **Game**
Maneja la lógica principal del juego:
- `processEvents`: Maneja los eventos del teclado.
- `update`: Actualiza el estado del jugador, plataformas y obstáculos.
- `render`: Renderiza el fondo, plataformas, obstáculos y jugador.

### 2. **Background**
- Renderiza la imagen de fondo.
- Escala la textura según el tamaño de la ventana.

### 3. **Player**
- Representa al jugador.
- Permite el movimiento, saltos y actualiza su posición.

### 4. **Platform**
- Administra las plataformas en movimiento.
- Reinicia las posiciones cuando salen de la pantalla.

### 5. **Obstacle**
- Administra los obstáculos que deben ser esquivados.
- Reinicia las posiciones cuando salen de la pantalla.

## Personalización
### Cambiar el Fondo
Para cambiar el fondo, reemplaza `background.png` en la carpeta `assets` con otra imagen del mismo nombre. Asegúrate de que la resolución sea adecuada para la ventana del juego.

### Ajustar la Dificultad
- **Velocidad de obstáculos**: Edita la variable `obstacleSpeed` en la clase `Game`.
- **Fuerza de salto**: Modifica `jumpStrength` en la clase `Game`.
- **Gravedad**: Cambia el valor de `gravity` en la clase `Game`.

## Errores Comunes
1. **No se encuentra la textura del fondo**:
   - Asegúrate de que `background.png` esté en la carpeta `assets`.
   - Verifica que la ruta del archivo sea correcta.

2. **SFML no instalado**:
   - Instala SFML y asegúrate de que esté en el `PATH` o configurado en tu entorno de compilación.

## Créditos
Proyecto desarrollado como una práctica de programación en C++ con integración de SFML. Puedes personalizarlo y expandirlo según tus necesidades.

¡Diviértete programando y jugando! 🚀

