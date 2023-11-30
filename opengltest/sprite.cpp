#include "sprite.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "GL/glut.h"
#include "GL/gl.h"
#include <iostream>

Sprite::Sprite(float x, float y, const std::string& imagePath)
    : x(x), y(y), imagePath(imagePath), scale(1.0f), rotation(0.0f) {
    LoadImg();
}

void Sprite::LoadImg() {
    int width, height, nrChannels;
    unsigned char* data = stbi_load(imagePath.c_str(), &width, &height, &nrChannels, 0);

    if (data) {
        glGenTextures(1, &tID);
        glBindTexture(GL_TEXTURE_2D, tID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cerr << "Failed to load texture: " << imagePath << std::endl;
    }

    stbi_image_free(data);
}

void Sprite::Draw() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tID);

    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(rotation, 0.0f, 0.0f, 1.0f);
    glScalef(scale, scale, 1.0f);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(-0.5f, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(0.5f, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(-0.5f, 0.5f);
    glEnd();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

float Sprite::GetX() const { return x; }
void Sprite::SetX(float x) { this->x = x; }

float Sprite::GetY() const { return y; }
void Sprite::SetY(float y) { this->y = y; }

float Sprite::GetScale() const { return scale; }
void Sprite::SetScale(float scale) { this->scale = scale; }

float Sprite::GetRotation() const { return rotation; }
void Sprite::SetRotation(float rotation) { this->rotation = rotation; }