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
	RenderingLoop(render);
	glutReshapeFunc(reshaping);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();

}


Game::~Game() {}

void Game::RenderingLoop(void (*func)(void)) {
	// Set the function that GLUT will call for rendering
	glutDisplayFunc(func);

	// Set the function that GLUT will call when idle
	//glutIdleFunc(func);
}

void Game::reshaping(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 500.0, 500.0, 0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::timer(int t)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

void Game::update()
{
	// Use to update player direction, bullet creation/direction, asteroid creation/direction etc.
}

