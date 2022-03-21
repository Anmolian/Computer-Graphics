#include <iostream>
#include <glut.h>
using namespace std;
void display() {
	glClearColor(0, 0, 0, 0); //black window
	cout << "Background_Set" << endl;
	glClear(GL_COLOR_BUFFER_BIT);
	int dx, dy, p, x, y;
	cout << "Coordinates of first point : ";
	int x1, y1;
	cin >> x1 >> y1;
	cout << "Coordinates of second point : ";
	int x2, y2;
	cin >> x2 >> y2;
	dx = x2 - x1;
	dy = y2 - y1;
	x = x1;
	y = y1;
	p = 2 * dy - dx;
	glBegin(GL_LINES);
	while (x < x2) {
		cout << "running points " << x << "," << y << endl;
		if (p >= 0) {
			glVertex2f(x*0.001, y*0.001);
			y++;
			p = p + 2 * dy - 2 * dx;
		}
		else {
			glVertex2f(x * 0.001, y * 0.001);
			p = p + 2 * dy;
		}
		x++;
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
