#pragma once
#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>
#include <GL/glut.h>

class Game {

private:
	int index;

public:
	Game();
	~Game();

	// Functions that deal with the Window 
	void Init(); // Creates Window Creation
	void InitW();
	static void RenderingLoop(void (*func)(void)); // Game Loop to keep the window displayed
	static void update();
	static void render();
	static void reshaping(int w, int h);
	static void timer(int t);


};


#endif
