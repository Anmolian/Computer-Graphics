#include <iostream>
#include <glut.h>
using namespace std;
void DrawLine(float x1, float y1, float x2, float y2) {
	glBegin(GL_LINES);
	glVertex2f(x1/100,y1/100);
	glVertex2f(x2 / 100, y2 / 100);
	glEnd();

}

void DrawRect(float xc, float yc, float len, float wid) {
	DrawLine(xc + (len / 2), yc + (wid / 2), xc + (len / 2), yc - (wid / 2));
	DrawLine(xc + (len / 2), yc - (wid / 2), xc - (len / 2), yc - (wid / 2));
	DrawLine(xc - (len / 2), yc - (wid / 2), xc - (len / 2), yc + (wid / 2));
	DrawLine(xc - (len / 2), yc + (wid / 2), xc + (len / 2), yc + (wid / 2));
}

void DrawCircle(float cx, float cy, float r)
{
	r = r / 100;
	cx = cx / 100;
	cy = cy / 100;
	int num_segments = 10000;
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}

void DrawEllipse(float xc,float yc,float rx,float ry) {
	xc *= 10;
	yc *= 10;
	rx *= 10;
	ry *= 10;
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
		glVertex2f((-x + xc) / 1000, (y + yc) / 1000);
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
}

void display() {
	glClearColor(0, 0, 0, 0); //black window
	glClear(GL_COLOR_BUFFER_BIT);
	GLfloat cur = 2;
	glPointSize(cur);
	//x y size 100
	DrawEllipse(0, 0, 50,20); //body
	// tail
	DrawLine(50, 0, 60, 10);
	DrawLine(60, 10, 60, -10);
	DrawLine(60, -10, 50, 0);
	// fin
	DrawLine(-10, -20, 10, -20);
	DrawLine(-10, -20, 0, -30);
	DrawLine(10, -20, 0, -30);
	DrawLine(-10, 20, 10, 20);
	DrawLine(-10, 20, 0, 30);
	DrawLine(10, 20, 0, 30);
	//eye
	DrawCircle(-30, 0, 2);
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
