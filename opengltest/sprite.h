#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include <string>

class Sprite {
public:
    // Constructor
    Sprite(float x, float y, const std::string& imagePath);

    // Function to load the image
    void LoadImg();

    // Function to draw the sprite
    void Draw();

    // Getters and setters for position
    float GetX() const;
    void SetX(float x);

    float GetY() const;
    void SetY(float y);

    float GetScale() const;
    void SetScale(float y);

    float GetRotation() const;
    void SetRotation(float y);

private:
    float x, y;              // Position of the sprite
    float scale = 1, rotation = 0;  // Translation of the sprite
    std::string imagePath;   // Path to the image file
    unsigned int tID;  // OpenGL texture ID

    // Helper function to generate texture
    void GenerateTexture();
};

#endif // SPRITE_H