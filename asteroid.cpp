#include "asteroid.h"

std::vector<Asteroid> asteroids;

void drawAsteroid(Asteroid& asteroid)
{
    glPushMatrix();
    glTranslatef(asteroid.asteroidXPos, asteroid.asteroidYPos, 0.0f);
    glScalef(20, 20, 1.0);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.5, 0.5, 0.5);  

    // Draw irregular shape for the asteroid
    const int numVertices = 8;
    for (int i = 0; i <= numVertices; ++i) {
        float angle = static_cast<float>(i) * 3.3 * M_PI / numVertices;
        float radius = 0.8 + 0.2 * std::cos(5.0 * angle);
        float xPos = radius * std::cos(angle);
        float yPos = radius * std::sin(angle);
        glVertex2f(xPos, yPos);
    }

    glEnd();

    glPopMatrix();
}

void asteroidMoving()
{
    for (auto& asteroid : asteroids) 
    {
        asteroid.asteroidXPos += 1.0f * cos(asteroid.asteroidAngle * M_PI / 180.0f);
        asteroid.asteroidYPos += 1.0f * sin(asteroid.asteroidAngle * M_PI / 180.0f);

        // Wrap asteroids around the screen
        if (asteroid.asteroidXPos < -800 / 2) 
        {
            asteroid.asteroidXPos = 800 / 2;
        }
        if (asteroid.asteroidXPos > 800 / 2) 
        {
            asteroid.asteroidXPos = -800 / 2;
        }
        if (asteroid.asteroidYPos < -600 / 2) 
        {
            asteroid.asteroidYPos = 600 / 2;
        }
        if (asteroid.asteroidYPos > 600 / 2) 
        {
            asteroid.asteroidYPos = -600 / 2;
        }
    }
}

void makeAsteroid()
{
    Asteroid asteroid;
    // Uses rand function to spawn in random locations of the screen
    asteroid.asteroidXPos = rand() % (2 * 800) - 800;
    asteroid.asteroidYPos = rand() % (2 * 600) - 600;
    asteroid.asteroidAngle = rand() % 360;
    asteroid.isNotHit = true;
    asteroids.push_back(asteroid);
}