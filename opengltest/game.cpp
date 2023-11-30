#include "game.h"


Game::Game()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(1376, 768, "Asteroids", NULL, NULL);
	glfwMakeContextCurrent(window);
	glViewport(0, 0, 1376, 768);
}

Game::~Game()
{
	glfwTerminate();
}

bool Game::windowClosed()
{
	return glfwWindowShouldClose(window);
}

void Game::render()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Game::update()
{
	// Used to update player direction, bullet creation/direction, asteroid creation/direction etc.
}

