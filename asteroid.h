#pragma once
#ifndef ASTEROID_H
#define ASTEROID_H

#include "player.h"
#include "bullet.h"

class Asteroid {

public:
	float asteroidXPos{};
	float asteroidYPos{};
	float asteroidAngle{};
	bool isNotHit{};
	Asteroid() : asteroidXPos(0.0f), asteroidYPos(0.0f), asteroidAngle(0.0f), isNotHit(false) {}
};

void drawAsteroid(Asteroid& asteroid);

void asteroidMoving();

void makeAsteroid();

#endif
