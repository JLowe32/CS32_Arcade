#include "player.h"
#define MAX_BULLETS 10

int posX{ 25 }, posY{ 25 };

char pDirection{};

Bullet bullets[MAX_BULLETS];

void drawBullet(Bullet& bullet) {
    if (!bullet.active) return;

    glPushMatrix();
    glTranslatef(bullet.x, bullet.y, 0);
    glBegin(GL_QUADS); // TODO: Choose Shapes
    glColor3f(1.0, 0.0, 0.0); // Bullet Color: Red
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();
    glPopMatrix();
}

void drawBullets() {
    for (int i = 0; i < MAX_BULLETS; ++i) {
        drawBullet(bullets[i]);
    }
}


void drawPlayer()
{
	if (pDirection == 'U')
	{
		if (posY != 49)
		{
			posY++;
		}
	}
	else if (pDirection == 'D')
	{
		if (posY != 1)
		{
			posY--;
		}
	}
	else if (pDirection == 'L')
	{
		if (posX != 1)
		{
			posX--;
		}
	}
	else if (pDirection == 'R')
	{
		if (posX != 49)
		{
			posX++;
		}
	}

	glBegin(GL_TRIANGLES);
	glColor3ub(0, 0, 255);
	glVertex2f(posX - 0.5f, posY - 0.5f);
	glVertex2f(posX + 0.5f, posY - 0.5f);
	glVertex2f(posX, posY + 0.5f);
	glEnd();

}
