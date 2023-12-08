#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#define _USE_MATH_DEFINES
#include <GL/freeglut.h>
#include <cmath>


class Player {

public:
	float playerXPos{};
	float playerYPos{};
	float playerAngle{};
	bool isMoving{};
	Player() : playerXPos(0.0f), playerYPos(0.0f), playerAngle(0.0f), isMoving(false) {}
};

void drawPlayer();

void movingPlayer();

#endif
