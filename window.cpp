#include "window.h"


bool gameOver{ false };
bool gameWin{ false };
bool gameStarted = false;
int score{ 0 };
int totalLives{ 3 };

void displayStartScreen() {
    // Display start screen text
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0f, 1.0f, 1.0f); // White color
    glRasterPos2i(-50, 0); // Position at the center

    std::string startText = "Press Enter to Start";
    for (char c : startText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
    glPopMatrix();
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	if (!gameStarted) {
		displayStartScreen();
	} else {
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

	if (gameOver)
	{
		MessageBox(NULL, L"Game Over", L"Game Over", 0);
		exit(0);
	}

	if (gameWin)
	{
		MessageBox(NULL, L"You Win!", L"You Win!", 0);
		exit(0);
	}

	glutSwapBuffers();

	displayScore();

	glutSwapBuffers();
	}
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
	glutSwapBuffers();
}

void keyboardInput(int key, int x, int y)
{
	if (!gameStarted && key == GLUT_KEY_ENTER) {
        gameStarted = true; // Start the game
    }
	
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
		float distanceSquared = (playShip.playerXPos - asteroid.asteroidXPos) * (playShip.playerXPos - asteroid.asteroidXPos) +
			(playShip.playerYPos - asteroid.asteroidYPos) * (playShip.playerYPos - asteroid.asteroidYPos);

		float sumRadiiSquared = (10.0f + 20.0f) * (10.0f + 20.0f); 

		if (distanceSquared <= sumRadiiSquared) 
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
				float distanceSquared = (bullet.bulletXPos - asteroidIt->asteroidXPos) * (bullet.bulletXPos - asteroidIt->asteroidXPos) +
					(bullet.bulletYPos - asteroidIt->asteroidYPos) * (bullet.bulletYPos - asteroidIt->asteroidYPos);

				float sumRadiiSquared = (2.0f + 20.0f) * (2.0f + 20.f); 

				if (distanceSquared <= sumRadiiSquared) 
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

	if (distanceSquared <= sumRadiiSquared) {
        bullet.isFired = false;
        asteroidIt = asteroids.erase(asteroidIt);
        score++; // Increment the score
        return true;
    }

}

void displayScore() {
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0f, 1.0f, 1.0f); // Set the color to white
    glRasterPos2i(-390, 280); // Set the position to top-left corner

    std::string scoreText = "Score: " + std::to_string(score);
    for (char c : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
    glPopMatrix();
}

