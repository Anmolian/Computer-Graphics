#include <iostream>
#include <glut.h>
using namespace std;
void display() {
	glClearColor(0, 0, 0, 0); //black window
	glClear(GL_COLOR_BUFFER_BIT);
	GLfloat cur = 2;
	glPointSize(cur);
	int x_centre, y_centre;
	cout << "Enter the centre of the circle : ";
	cin >> x_centre >> y_centre;
	cout << "Enter the radius of the cirle : ";
	int radius;
	cin >> radius;
	int x = radius;
	int y = 0;
	//starting at the radius in the first octant
	int p = 1 - radius;
	glBegin(GL_POINTS);
	while (x > y) {
		y++;
		if (p <= 0)p = p + 2 * y + 1;
		else {
			x--;
			p = p + 2 * y - 2 * x + 1;
		}
		if (x < y)break;
		glVertex2f((x + x_centre)*0.0001, (y + y_centre)*0.0001);
		glVertex2f((-x + x_centre) * 0.0001, (y + y_centre) * 0.0001);
		glVertex2f((x + x_centre) * 0.0001, (-y + y_centre) * 0.0001);
		glVertex2f((-x + x_centre) * 0.0001, (-y + y_centre) * 0.0001);
		if (x != y) {
			glVertex2f((y + x_centre)*0.0001, (x + y_centre)*0.0001);
			glVertex2f((-y + x_centre) * 0.0001, (x + y_centre) * 0.0001);
			glVertex2f((y + x_centre) * 0.0001, (-x + y_centre) * 0.0001);
			glVertex2f((-y + x_centre) * 0.0001, (-x + y_centre) * 0.0001);
		}
	}
	glEnd();
	glFlush();
}
