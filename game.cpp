#include "game.h"


Game::Game()
{
	Init();
}

void Game::InitW()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Game::Init()
{
	int argc{};
	char* argv[1] = { (char*)"" };
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutInitWindowSize(800, 600);
	glutCreateWindow("Asteroid");
	InitW();
	glutDisplayFunc(render);
	glutReshapeFunc(reshaping);
	glutTimerFunc(0, timer, 0);
	glutSpecialFunc(keyBoardInput);
	glutMainLoop();

}


Game::~Game() {}

void Game::reshaping(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 50.0, 0, 50.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::keyBoardInput(int key, int, int)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		pDirection = 'U';
		break;
	case GLUT_KEY_DOWN:
		pDirection = 'D';
		break;
	case GLUT_KEY_RIGHT:
		pDirection = 'R';
		break;
	case GLUT_KEY_LEFT:
		pDirection = 'L';
		break;
	}

	glutPostRedisplay();

    if (key == ' ') { // Spacebar = Firing
        for (int i = 0; i < MAX_BULLETS; ++i) {
            if (!bullets[i].active) {
                bullets[i].active = true;
                bullets[i].x = posX; 
                bullets[i].y = posY;
                break;
            }
        }
    }

}

void Game::timer(int t)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 20, timer, 0);
}



void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawPlayer();
	AsteroidMoving();
	glFlush();
	glutSwapBuffers();

}

void Game::update() {
    for (int i = 0; i < MAX_BULLETS; ++i) {
        if (bullets[i].active) {
            bullets[i].y += 1.0f; // TODO: Adjustment of bullet Speed
            if (bullets[i].y > 50) bullets[i].active = false; // Deactivation: Out of Bounds
        }
    }

	for (int i = 0; i < MAX_BULLETS; ++i) {
        if (checkCollision(bullets[i], asteroidX, asteroidY, asteroidSize) ||
            checkCollision(bullets[i], asteroid2X, asteroid2Y, asteroidSize) ||
            checkCollision(bullets[i], asteroid3X, asteroid3Y, asteroidSize)) {
            bullets[i].active = false;
            // TODO: Code to handle asteroid destruction
        }
    }
}




