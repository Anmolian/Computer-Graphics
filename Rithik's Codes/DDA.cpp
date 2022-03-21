#include <iostream>
#include <glut.h>
using namespace std;
void display() {
	glClearColor(0,0,0,0); //black window
	cout << "Background_Set" << endl;
	glClear(GL_COLOR_BUFFER_BIT);
	GLfloat cur = 3; // setting pixel size
	glPointSize(cur); // setting point size to GLfloat
	cout << "pixel size set to : " << int(cur) << endl;
	float xa, ya;
	cin >> xa >> ya;
	float xb, yb;
	cin >> xb >> yb;
	float dx = xb - xa;
	float dy = yb - ya;
	int steps = 0;
	if (dx > dy) {
		steps = dx;
	}
	else {
		steps = dy;
	}
	float xinc = dx / steps;
	float yinc = dy / steps;
	int counter = 0;
	cout << "starting coordinates : " << xa << "," << ya << endl;
	cout << "ending coordinates : " << xb << "," << yb << endl;
	cout << "steps : " << steps << endl;
	glBegin(GL_POINTS);
	while (counter < steps) {
		cout << "running point : " << xa << "," << ya << endl;
		glVertex2f(xa / 100, ya / 100);
		xa += xinc;
		ya += yinc;
		counter++;
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
