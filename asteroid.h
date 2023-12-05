#pragma once
#ifndef ASTEROID_H
#define ASTEROID_H

#define _USE_MATH_DEFINES
#include "game.h"
#include <cmath>


void drawAsteroid(float x, float y, float size);

void updateAsteroidPosition(float& x, float& y, float velocityX, float velocityY);

void AsteroidMoving();

bool checkCollision(Bullet& bullet, float ax, float ay, float asize);




#endif
