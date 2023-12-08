#include "window.h"


bool gameOver{ false };
bool gameWin{ false };
int score{ 0 };
int totalLives{ 3 };

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	drawPlayer();
	
	// Goes through the bullets vector, properly drawing each bullet
	for (auto& bullet : bullets) 
	{
		if (bullet.isFired) 
		{
			drawBullet(bullet);
		}
	}

	// Does the same like bullets, but for asteroids
	for (auto& asteroid : asteroids) 
	{
		if (asteroid.isNotHit)
		{
			drawAsteroid(asteroid);
		}
	}

	// Creates messageBoxes depending on winning or losing 

	/*if (gameOver)
	{
		MessageBox(NULL, L"Game Over", L"Game Over", 0);
		exit(0);
	}

	if (gameWin)
	{
		MessageBox(NULL, L"You Win!", L"You Win!", 0);
		exit(0);
	}
	*/
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-800 / 2, 800 / 2, -600.0 / 2, 600.0 / 2);
	glMatrixMode(GL_MODELVIEW);
}

void update(int value) 
{
	// Function handles player movement, asteroid movement, and shooting
	// Also checks for collision conditions to reset player to the center of the screen or update scores/health
	movingPlayer();
	bulletMoving();
	glutPostRedisplay();
	asteroidMoving();

	if (checkShipAsteroidCollision()) 
	{
		playShip.playerXPos = 0.0f;
		playShip.playerYPos = 0.0f;
		totalLives--;
		std::cout << "Lives: " << totalLives << '\n';

		if (totalLives == 0)
		{
			gameOver = true;
		}
	}

	if (checkBulletAsteroidCollision()) 
	{
		score++;
		std::cout << "Score: " <<  score << '\n';
	}

	if (asteroids.empty())
	{
		gameWin = true;
	}

	glutPostRedisplay();
	glutTimerFunc(16, update, 0); 
}

void keyboardInput(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		playShip.isMoving = true;
		break;
	case GLUT_KEY_LEFT:
		playShip.playerAngle += 15.0f;
		break;
	case GLUT_KEY_RIGHT:
		playShip.playerAngle -= 15.0f;
		break;
	case GLUT_KEY_CTRL_L:
		makeBullet();
		break;
	}
}

void keyboardInputPressed(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		playShip.isMoving = false;
		break;
	}
}

void spawnAsteroids()
{
	for (int i = 0; i < 20; i++)
	{
		makeAsteroid();
	}
}

bool checkShipAsteroidCollision() 
{
	// Handles Ship and Asteroid Collision by measursing the distance from the ship and asteroid
	for (auto& asteroid : asteroids) 
	{
		if (sqrt(playShip.playerXPos - asteroid.asteroidXPos) * (playShip.playerXPos - asteroid.asteroidXPos) +
			(playShip.playerYPos - asteroid.asteroidYPos) * (playShip.playerYPos - asteroid.asteroidYPos) <= (20.0f * 20.0f))
		{
			return true;  
		}
	}

	return false;  
}

bool checkBulletAsteroidCollision() 
{
	// Handles bullet and asteroid collision the same way as the ship and asteroid collision
	for (auto& bullet : bullets) 
	{
		if (bullet.isFired) 
		{
			auto asteroidIt = asteroids.begin();
			while (asteroidIt != asteroids.end()) 
			{
				if (sqrt(bullet.bulletXPos - asteroidIt->asteroidXPos) * (bullet.bulletXPos - asteroidIt->asteroidXPos) +
					(bullet.bulletYPos - asteroidIt->asteroidYPos) * (bullet.bulletYPos - asteroidIt->asteroidYPos) <= (20.0f * 20.0f))
				{
					bullet.isFired = false;  
					asteroidIt = asteroids.erase(asteroidIt);  
					return true; 
				}
				else 
				{
					++asteroidIt;
				}
			}
		}
	}
	return false; 
}

