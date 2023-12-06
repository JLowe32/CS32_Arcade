#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <GL/freeglut.h>

void drawBullets();
void drawPlayer();

struct Bullet {
    float x, y;     // Bullet Position
    bool active;    // Bullet Activision Check
};

void updateBulletPosition(Bullet& bullet, float bulletVelocityX, float bulletVelocityY);
void bulletMoving(Bullet& bullet);
void drawBullet(Bullet& bullet);

#endif 
