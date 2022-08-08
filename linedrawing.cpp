#include <iostream>
#include <glut.h>
using namespace std;
void display() {
	glClearColor(0,0,0,0); //black window
	cout << "Background_Set" << endl;
	glClear(GL_COLOR_BUFFER_BIT);
	GLfloat cur = 3; // setting pixel size
	glPointSize(cur); // setting point size to GLfloat
	cout << "pixel size set to : " <<int(cur) << endl;
	glBegin(GL_LINES);
	glVertex2f(0.20,0.20);
	glVertex2f(0.20,-0.20);

	glVertex2f(0.20, -0.20);
	glVertex2f(-0.20, -0.20);

	glVertex2f(-0.20, -0.20);
	glVertex2f(-0.20, 0.20);

	glVertex2f(-0.20, 0.20);
	glVertex2f(0.20, 0.20);
	glEnd();
	glFlush();
}
void init() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("My Window");
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
