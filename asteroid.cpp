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

void AsteroidMoving()
{
    asteroidX += asteroidVelocityX;
    asteroidY += asteroidVelocityY;

    asteroid2X += asteroidVelocityX;
    asteroid2Y += asteroidVelocityY;

    asteroid3X += asteroidVelocityX;
    asteroid3Y += asteroidVelocityY;

    // Wrap around the screen
    if (asteroidX < 0.0f) asteroidX = 49.0f;
    if (asteroidX > 49.0f) asteroidX = 0.0f;
    if (asteroidY < 0.0f) asteroidY = 49.0f;
    if (asteroidY > 49.0f) asteroidY = 0.0f;

    if (asteroid2X < 0.0f) asteroid2X = 49.0f;
    if (asteroid2X > 49.0f) asteroid2X = 0.0f;
    if (asteroid2Y < 0.0f) asteroid2Y = 49.0f;
    if (asteroid2Y > 49.0f) asteroid2Y = 0.0f;

    if (asteroid3X < 0.0f) asteroid3X = 49.0f;
    if (asteroid3X > 49.0f) asteroid3X = 0.0f;
    if (asteroid3Y < 0.0f) asteroid3Y = 49.0f;
    if (asteroid3Y > 49.0f) asteroid3Y = 0.0f;



    // Draw the asteroid at the updated position
    drawAsteroid(asteroidX, asteroidY, asteroidSize);
    drawAsteroid(asteroid2X, asteroid2Y, asteroidSize);
    drawAsteroid(asteroid3X, asteroid3Y, asteroidSize);
}


