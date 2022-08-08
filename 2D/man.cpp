#include <iostream>
#include <glut.h>
using namespace std;
void DrawLine(float x1, float y1, float x2, float y2) {
	glBegin(GL_LINES);
	glVertex2f(x1/100,y1/100);
	glVertex2f(x2 / 100, y2 / 100);
	glEnd();

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


void display() {
	glClearColor(0, 0, 0, 0); //black window
	glClear(GL_COLOR_BUFFER_BIT);
	GLfloat cur = 2;
	glPointSize(cur);
	//x y size 100
	DrawLine(0, 20, 0, -40);
	DrawLine(0, -40, 20, -60);
	DrawLine(0, -40, -20, -60);
	DrawCircle(0, 30, 10);
	DrawLine(-30, 0, 30, 0);
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
