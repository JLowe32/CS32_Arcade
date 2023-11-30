#pragma once
#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>
#include <GL/glut.h>


class Game {

private:
	GLFWwindow* window{};

public:
	Game();
	~Game();

	// Functions 
	void Init(); // Will be used to initalize shaders 
	void processInput();
	bool windowClosed();
	void update();
	void render();

};


#endif
