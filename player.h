#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <GL/freeglut.h>

void drawPlayer();

struct Bullet {
    float x, y;     // Bullet Position
    bool active;    // Bullet Activision Check
};


#endif 