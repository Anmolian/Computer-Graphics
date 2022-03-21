#include <GL/glut.h>
#include<cmath>
#include<iostream>

using namespace std;

/* GLUT callback Handlers */
void myInit (void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);//background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // setting window dimension in X- and Y- direction
    gluOrtho2D(-1000, 1000, -1000, 1000);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
static void translation()
{
    int x1 = -100, x2 = 300, x3 = 250, y1 = 200, y2 = 200, y3 = 400;
    int tx = 200, ty = 300;
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1+tx, y1+ty);
    glVertex2i(x2+tx, y2+ty);
    glVertex2i(x3+tx, y3+ty);
    glEnd();

    glFlush();
}
static void rotation(void)
{
    int x1= -100,x2=300,x3=250,y1=200,y2=200,y3=400;
    float pi=3.14159;
    float angle = 90;
    float theta = angle*pi / 180;

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glEnd();

    //Anti-Clockwise
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1*cos(theta) - y1*sin(theta), x1*sin(theta) + y1*cos(theta));
    glVertex2i(x2*cos(theta) - y2*sin(theta), x2*sin(theta) + y2*cos(theta));
    glVertex2i(x3*cos(theta) - y3*sin(theta), x3*sin(theta) + y3*cos(theta));
    glEnd();

    //Clockwise
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1*cos(theta) + y1*sin(theta), -x1*sin(theta) + y1*cos(theta));
    glVertex2i(x2*cos(theta) + y2*sin(theta), -x2*sin(theta) + y2*cos(theta));
    glVertex2i(x3*cos(theta) + y3*sin(theta), -x3*sin(theta) + y3*cos(theta));
    glEnd();

    glutSwapBuffers();
}
static void scaling(void)
{
    int x1= -100,x2=300,x3=250,y1=200,y2=200,y3=400;

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(x1,y1);
    glVertex2f(x2*2,y2);
    glVertex2f(x3*2,y3*2);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glVertex2i(x3,y3);
    glEnd();

    glutSwapBuffers();
}

static void shearing(void)
{
    int x1= -100,x2=300,x3=250,y1=200,y2=200,y3=400;

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(x1 + y1,y1);
    glVertex2f(x2 + y2*2,y2);
    glVertex2f(x3 + y3,y3);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glVertex2i(x3,y3);
    glEnd();

    glutSwapBuffers();
}
static void reflection(void)
{
    int x1= 0,x2=500,x3=800,y1=0,y2=0,y3=600;

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(-x1,-y1);
    glVertex2i(-x2,-y2);
    glVertex2i(-x3,-y3);
    glEnd();

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glVertex2i(x3,y3);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(-x1,y1);
    glVertex2i(-x2,y2);
    glVertex2i(-x3,y3);
    glEnd();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(x1,-y1);
    glVertex2i(x2,-y2);
    glVertex2i(x3,-y3);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);    // Use single color buffer and no depth buffer.
    glutInitWindowSize(500,500);         // Size of display area, in pixels.
    glutInitWindowPosition(0,0);     // Location of window in screen coordinates.

    glutCreateWindow("Transformations"); // Parameter is window title.
    myInit();

    glutDisplayFunc(rotation);            // Called when the window needs to be redrawn.
    glutMainLoop(); // Run the event loop!  This function does not return.
                    // Program ends when user closes the window.
    return 0;
}
