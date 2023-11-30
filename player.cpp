#include "player.h"

int posX{ 25 }, posY{ 25 };

char pDirection{};

void drawPlayer()
{
	if (pDirection == 'U')
	{
		if (posY != 49)
		{
			posY++;
			//pDirection = 'N';
		}
	}
	else if (pDirection == 'D')
	{
		if (posY != 1)
		{
			posY--;
			//pDirection = 'N';
		}
	}
	else if (pDirection == 'L')
	{
		if (posX != 1)
		{
			posX--;
			//pDirection = 'N';
		}
	}
	else if (pDirection == 'R')
	{
		if (posX != 49)
		{
			posX++;
			//pDirection = 'N';
		}
	}
	else if (pDirection == 'N')
	{
		posX = posX;
		posY = posY;
	}

	glBegin(GL_TRIANGLES);
	glColor3ub(0, 0, 255);
	glVertex2f(posX - 0.5f, posY - 0.5f);
	glVertex2f(posX + 0.5f, posY - 0.5f);
	glVertex2f(posX, posY + 0.5f);
	glEnd();

}