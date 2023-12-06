#pragma once
#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "asteroid.h"
#include <GL/glut.h>


extern char pDirection;
extern int posX;
extern int posY;
extern Bullet bullets[10];

class Game {

private:

public:
	Game();
	~Game();

	// Functions that deal with the Window 
	void Init(); // Creates Window Creation
	void InitW();
	static void update();
	static void render();
	static void reshaping(int w, int h);
	static void timer(int t);
	static void keyBoardInput(int key, int, int);


};


#endif
