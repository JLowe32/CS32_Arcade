#include "player.h"

Player playShip;

void drawPlayer()
{
    glPushMatrix();
    glTranslatef(playShip.playerXPos, playShip.playerYPos, 0.0f);
    glRotatef(playShip.playerAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(0.0f, 0.0f, 255.0f); 
    glBegin(GL_TRIANGLES);
    glVertex2f(15.0f, 0.0f);
    glVertex2f(0.0f, -5.0f);
    glVertex2f(0.0f, 5.0f);
    glEnd();

    glPopMatrix();
}

void movingPlayer()
{
    // Handles moving the player in the correction direction using the angle its pointing towards
    if (playShip.isMoving)
    {
        playShip.playerXPos += 2.5f * cos(playShip.playerAngle * M_PI / 180.0f);
        playShip.playerYPos += 2.5f * sin(playShip.playerAngle * M_PI / 180.0f);
    }
}



