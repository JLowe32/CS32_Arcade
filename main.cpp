#include "window.h"
#include <GL/glut.h>


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutInitWindowSize(800, 600);
	glutCreateWindow("Asteroid");
	glutReshapeFunc(reshape);
	glutDisplayFunc(render);
	glutTimerFunc(25, update, 0);
	glutSpecialFunc(keyboardInput);
	glutSpecialUpFunc(keyboardInputPressed);
	spawnAsteroids();
	glutMainLoop();
}