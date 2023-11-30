#include "Draw.h"
#include "Sprite.h"
#include <vector>

//std::vector<Sprite*> sprites; // A vector to hold Sprite objects

void Draw::InitOpenGL() {
    // Initialize GLUT
    int argc = 0;
    char* argv[] = { (char*)"" }; // Dummy arguments for GLUT init
    glutInit(&argc, argv);

    // Set up display mode: Double buffer, RGBA color
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    // Initialize some basic OpenGL settings
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

bool Draw::windowClosed()
{
    return glutGetWindow();
}

void Draw::CreateWin(const char* title, int width, int height) {
    // Set window size
    glutInitWindowSize(width, height);

    // Create the window with given title
    glutCreateWindow(title);

    // Set the clear color to black (optional)
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Draw::SetRenderingLoop(void (*func)(void)) {
    // Set the function that GLUT will call for rendering
    glutDisplayFunc(func);

    // Set the function that GLUT will call when idle
    glutIdleFunc(func);
}

void Draw::UpdateFrame() {
    // Update logic for each sprite (if needed)
    for (auto Sprite : sprites) {
        // Example: Update sprite position or other properties
    }
}

void Draw::AddSprite(Sprite* sprite) {
    sprites.push_back(sprite);
}

void Draw::RemoveSprite(Sprite* sprite) {
    //TODO
}

/*Sprite* Draw::GetSpriteAt(int index) {
    //DOTO
}*/

void Draw::RenderFrame() {
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Render each sprite
    for (auto Sprite : sprites) {
        Sprite->Draw();
    }

    // Swap the buffers
    glutSwapBuffers();
}