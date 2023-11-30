#pragma once
#ifndef DRAW_H
#define DRAW_H

#include <GL/glut.h>
#include "sprite.h"
#include <vector>

class Draw {
public:
    // Initialize OpenGL settings
    static void InitOpenGL();

    // Function to create a window
    static void CreateWin(const char* title, int width, int height);

    // Set up the rendering loop
    static void SetRenderingLoop(void (*func)(void));

    // Function to update frame (can be expanded or modified)
    static void UpdateFrame();

    // Function to render frame (can be expanded or modified)
    static void RenderFrame();

    bool static windowClosed();

    /*
    static void addSprite(float x, float y, const std::string& imagePath)
    {
        Sprite* temp_Sprite(x, );
    }
    */

    // Helper functions for sprites
    static void AddSprite(Sprite* sprite);

    static void RemoveSprite(Sprite* sprite);

    //static Sprite* GetSpriteAt(int index);


private:
    // Add any private helper functions or members here if needed
    static std::vector<Sprite*> sprites;
};

#endif // DRAW_H