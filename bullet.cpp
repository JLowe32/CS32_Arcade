#include "bullet.h"

std::vector<Bullet> bullets;

void drawBullet(Bullet& bullet)
{
    glPushMatrix();
    glTranslatef(bullet.bulletXPos, bullet.bulletYPos, 0.0f);
    glRotatef(bullet.bulletAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(1.0f, 0.0f, 0.0f); 
    glBegin(GL_POLYGON);
    glScalef(5.0f, 5.0f, 1.0f);
    glVertex2f(-4.0f, -0.5f);
    glVertex2f(-4.0f, 0.5f);
    glVertex2f(4.0f, 0.5f);
    glVertex2f(4.0f, -0.5f);
    glEnd();

    glPopMatrix();
}

void bulletMoving()
{
    // Handles the bullet movement by moving towards the direction its facing 
    for (auto& bullet : bullets) 
    {
        if (bullet.isFired) {
            bullet.bulletXPos += 10.0f * cos(bullet.bulletAngle * M_PI / 180.0f);
            bullet.bulletYPos += 10.0f * sin(bullet.bulletAngle * M_PI / 180.0f);

            // Delete bullet when out of screen
            if (bullet.bulletXPos < -800 / 2 || bullet.bulletXPos> 800 / 2 || bullet.bulletYPos < -600 / 2 || bullet.bulletYPos > 600 / 2) 
            {
                bullet.isFired = false;
            }
        }
    }
}

void makeBullet() 
{
    Bullet bullet;
    bullet.bulletXPos = playShip.playerXPos;
    bullet.bulletYPos = playShip.playerYPos;
    bullet.bulletAngle = playShip.playerAngle;
    bullet.isFired = true;
    bullets.push_back(bullet);
}