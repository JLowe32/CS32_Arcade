#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include "player.h"
#include "bullet.h"
#include "asteroid.h"
#include <GL/glut.h>
#include <iostream>
#include <string>
#include <GL/freeglut.h>

extern Player playShip;
extern std::vector<Bullet> bullets;
extern std::vector<Asteroid> asteroids;
extern bool gameStarted;


// Functions to deal with Window Creation 

void render();

void reshape(int w, int h);

void update(int value);

void keyboardInput(int key, int x, int y);

void keyboardInputPressed(int key, int x, int y);

void spawnAsteroids();

void displayScore();

void displayStartScreen();

void displayEndScreen();

// Functions to deal with Collision

bool checkShipAsteroidCollision();

bool checkBulletAsteroidCollision();



#endif
