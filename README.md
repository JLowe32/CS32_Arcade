# Asteroid Game Program 
This project accomodates requirements through the recreation of a 2D space-themed arcade game called "Asteroids" through the development in C++ with OpenGL for rendering. The game features a player-controlled triangle mimicking a spaceship navigating through a field of wild asteroids. The main objective of the game is to continually dodge asteroids and navigate, challenging yourself to see how long you can survive through the task of dodging.  

## Game Features
- Player Movement
- Asteroids(NPC)
- Cool black background of the empty space!

## Game Controls
**Movement:**
- Arrow `Up`: Move the spaceship forward.  
- Arrow `Left`: Rotate the spaceship left. 
- Arrow `Right`: Rotate the spaceship right.
- Left `Ctrl`: To shoot bullets.


## Compilation and Execution
To compile and run the game, ensure that you have the required libraries installed. Use the following command to compile the game:
```
g++ -o AsteroidGame main.cpp game.cpp asteroid.cpp player.cpp -lGL -lGLU -lglut
```

## Files

**Source File:**
- `bullet.cpp`: Handles bullet creation and shooting.
- `asteroid.cpp`: Implements functionality and visual representation of asteroids.
- `main.cpp`: Manages the main game loop, window handling, and overall game interaction.
- `player.cpp`: Handles spaceship functionality, including movement and rendering.
- `window.cpp`: Manages window handling.
- `Makefile`: Contains the build instructions for the project.

**Header Files:**
- `bullet.h`: Bullet related functions.
- `asteroid.h`: Declares asteroid-related functions and properties.
- `window.h`:  Game logic; declarations of game-related functions.
- `player.h`: Handles spaceship, declaring functions and properties related to the player.
