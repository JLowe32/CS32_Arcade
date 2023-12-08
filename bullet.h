#pragma once
#ifndef BULLET_H
#define BULLET_H

#include "player.h"
#include <vector>

extern Player playShip;

class Bullet {

public:
	float bulletXPos{};
	float bulletYPos{};
	float bulletAngle{};
	bool isFired{};
	Bullet() : bulletXPos(0.0f), bulletYPos(0.0f), bulletAngle(0.0f), isFired(false) {}
};

void drawBullet(Bullet& bullet);

void bulletMoving();

void makeBullet();


#endif