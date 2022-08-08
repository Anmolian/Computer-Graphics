#include <iostream>
#include <glut.h>
using namespace std;
void DrawLine(float x1, float y1, float x2, float y2) {
	glBegin(GL_LINES);
	glVertex2f(x1/100,y1/100);
	glVertex2f(x2 / 100, y2 / 100);
	glEnd();
}void DrawRect(float xc, float yc, float len, float wid) {
	DrawLine(xc + (len / 2), yc + (wid / 2), xc + (len / 2), yc - (wid / 2));
	DrawLine(xc + (len / 2), yc - (wid / 2), xc - (len / 2), yc - (wid / 2));
	DrawLine(xc - (len / 2), yc - (wid / 2), xc - (len / 2), yc + (wid / 2));
	DrawLine(xc - (len / 2), yc + (wid / 2), xc + (len / 2), yc + (wid / 2));
}
void display() {
	glClearColor(0, 0, 0, 0); //black window
	glClear(GL_COLOR_BUFFER_BIT);
	GLfloat cur = 2;
	glPointSize(cur);
	//x y size 100
	DrawRect(0, 0, 100, 50); // house base
	DrawRect(-15, -10, 20,30); // door
	DrawRect(22.5, 0, 25, 20); //window
	// triangle
	DrawLine(50, 25, 0, 65);
	DrawLine(0, 65, -50, 25);
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
