#include "game.h"
#include "draw.h"
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
	/*
	Game game{};

	while (!game.windowClosed())
	{
		game.update();
		game.render();
	}



	*/


	Draw window{};
	Sprite sprite(250, 260, "Test.png");

	window.InitOpenGL();
	window.CreateWin("Asteroids", 600, 800);
	window.AddSprite(&sprite);

	while (window.windowClosed())
	{
		window.RenderFrame();
	}

	

	return 0;

}