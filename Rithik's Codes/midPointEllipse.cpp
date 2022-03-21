#include <iostream>
#include <glut.h>
using namespace std;
void display() {
	glClearColor(0, 0, 0, 0); //black window
	glClear(GL_COLOR_BUFFER_BIT);
	GLfloat cur = 2;
	glPointSize(cur);
	cout << "Enter major and minor radius for the ellipse : " << endl;
	float rx, ry;
	cin >> rx >> ry;
	rx = rx * 10;
	ry = ry * 10;
	cout << "Enter the centre of the ellipse : " << endl;
	float xc, yc;
	cin >> xc >> yc;
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;
	//for region 1 of the ellipse
	//decision parameter
	d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;
	glBegin(GL_POINTS);
	while (dx < dy) {
		//printing points based on 4 way symmetry
		glVertex2f((x + xc) / 1000, (y + yc) / 1000);
		glVertex2f((-x + xc) / 1000, (y + yc) /1000);
		glVertex2f((x + xc) / 1000, (-y + yc) / 1000);
		glVertex2f((-x + xc) / 1000, (-y + yc) / 1000);
		//updating decision parameter and checking the next point
		if (d1 < 0)
		{
			x++;
			dx = dx + (2 * ry * ry);
			d1 = d1 + dx + (ry * ry);
		}
		else
		{
			x++;
			y--;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d1 = d1 + dx - dy + (ry * ry);
		}
	}
	// decision parameter for region 2
	d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
		((rx * rx) * ((y - 1) * (y - 1))) -
		(rx * rx * ry * ry);
	while (y >= 0) {
		// drawing points for 4 way symmetry
		glVertex2f((x + xc) / 1000, (y + yc) / 1000);
		glVertex2f((-x + xc) / 1000, (y + yc) / 1000);
		glVertex2f((x + xc) / 1000, (-y + yc) / 1000);
		glVertex2f((-x + xc) / 1000, (-y + yc) / 1000);
		//updating parameter value and checking next point
		if (d2 > 0)
		{
			y--;
			dy = dy - (2 * rx * rx);
			d2 = d2 + (rx * rx) - dy;
		}
		else
		{
			y--;
			x++;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d2 = d2 + dx - dy + (rx * rx);
		}
	}
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
