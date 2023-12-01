#include "asteroid.h"

float asteroidX = 2.0f;
float asteroidY = 2.0f;
float asteroidSize = 1.3f;
float asteroidVelocityX = 0.5f;
float asteroidVelocityY = 0.5f;
float asteroid2X = 23.0f;
float asteroid2Y = 36.0f;
float asteroid3X = 27.0f;
float asteroid3Y = 6.0f;

void drawAsteroid(float x, float y, float size)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glScalef(size, size, 1.0);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.5, 0.5, 0.5);  // Gray color for the asteroid

    // Center of the asteroid
    glVertex2f(0.0, 0.0);

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

void updateAsteroidPosition(float& x, float& y, float velocityX, float velocityY) {
    x += velocityX;
    y += velocityY;

    // Wrap around display screen 
    if (x < 0.0f) x = 49.0f;
    if (x > 49.0f) x = 0.0f;
    if (y < 0.0f) y = 49.0f;
    if (y > 49.0f) y = 0.0f;
}

void AsteroidMoving() {
    updateAsteroidPosition(asteroidX, asteroidY, asteroidVelocityX, asteroidVelocityY);
    updateAsteroidPosition(asteroid2X, asteroid2Y, asteroidVelocityX, asteroidVelocityY);
    updateAsteroidPosition(asteroid3X, asteroid3Y, asteroidVelocityX, asteroidVelocityY);

    // Asteroids at updated positions
    drawAsteroid(asteroidX, asteroidY, asteroidSize);
    drawAsteroid(asteroid2X, asteroid2Y, asteroidSize);
    drawAsteroid(asteroid3X, asteroid3Y, asteroidSize);
}

