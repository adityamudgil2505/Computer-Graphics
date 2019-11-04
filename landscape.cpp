#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
 
#define PI 3.14159265358979
 
using namespace std;

struct coordinates{
	float x;	float y;
	coordinates(float a, float b):x(a), y(b){}
};

struct colour{
	float x;	float y;	float z;
	colour(float a, float b, float c):x(a), y(b), z(c){}
};


void Circle(float cx, float cy, float radius, struct colour c, int pSize=1) {
	float x, y;
	glBegin(GL_POINTS);
	glColor3f(c.x, c.y, c.z);
	glPointSize(pSize);
	for (float i = 0; i < 360; i += 0.1) {
		x = cx + radius * cos(i*PI / 180);
		y = cy + radius * sin(i*PI / 180);
		glVertex2f(x, y);
	}
	glEnd();
}
void partCircle(float cx, float cy, float radius, float sAngle, float eAngle, struct colour c, float pSize=1) {
	float x, y;
	glBegin(GL_POINTS);
	glColor3f(c.x, c.y, c.z);
	glPointSize(pSize);
	for (float i = sAngle; i < eAngle; i += 0.001) {
		x = cx + radius * cos(i*PI / 180);
		y = cy + radius * sin(i*PI / 180);
		glVertex2f(x, y);
	}
	glEnd();
}
 
 
void line(int x1, int y1, int x2, int y2, struct colour c, int pSize=1) {
	GLfloat x, y;
	glBegin(GL_POINTS);
	glColor3f(c.x, c.y, c.z);
	glPointSize(pSize);
	for (float i = 0; i < 1; i += 0.0001) {
		x = x1 * (1 - i) + x2 * i;
		y = y1 * (1 - i) + y2 * i;
		glVertex2f(x, y);
	}
	glEnd();
}

void lineDash(int x1, int y1, int x2, int y2, struct colour c, int pSize=1) {
	GLfloat x, y;
	glBegin(GL_POINTS);
	glColor3f(c.x, c.y, c.z);
	glPointSize(pSize);
	for (float i = 0; i < 1; i += 0.1) {
		for(float j=0; j<0.02; j+=0.0001)
		{	x = x1 * (1 - i-j) + x2 * (i+j);
			y = y1 * (1 - i-j) + y2 * (i+j);
			glVertex2f(x, y);
		}		
	}
	glEnd();
}

void triangle(int x1, int y1, int x2, int y2, int x3, int y3, struct colour c, int pSize=1) {
	GLfloat x, y;
	glColor3f(c.x, c.y, c.z);
	glPointSize(pSize);
	glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void rect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, struct colour c, int pSize=1) {
	GLfloat x, y;
	glColor3f(c.x, c.y, c.z);
	glPointSize(pSize);
	glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}
 
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	// glBegin(GL_POINTS);
	glColor3f(0, 1, 1);
	colour c(1, 1, 0);

	// road
	c.x=c.y=c.z=0.2;
	line(10, 1000, 1900, 1000, c, 5);
	line(10, 900, 1900, 700, c, 5);
	// divider
	c.x=c.y=c.z=0.8;
	lineDash(10, 950, 1900, 850, c, 5);
	
	//mountain
	c.x=1;c.y=0.5;c.z=0.2;
	line(10, 900, 700, 400, c, 5);
	line(700, 400, 950, 800, c, 5);
	line(890, 700, 1300, 350, c, 5);
	line(1300, 350, 1900, 700, c, 5);

	// windmill
	c.x=0.4;c.y=0.8;c.z=0.8;
	triangle(100, 900, 200, 900, 150, 700, c);
	c.x=0.8;c.y=0.8;c.z=0.8;
	triangle(150, 700, 130, 600, 170, 600, c);
	triangle(150, 700, 50, 710, 70, 750, c);
	triangle(150, 700, 250, 710, 230, 750, c);
	

	//sun
	c.x=1;c.y=1;c.z=0.2;
	partCircle(900, 680, 50, 220, 330, c, 15);

	// house
	c.x=0.8;c.y=0.8;c.z=0.8;
	rect(350, 850, 350, 700, 450, 700, 450, 850, c);
	c.x=0.4;c.y=0.8;c.z=0.8;
	rect(450, 850, 450, 700, 600, 650, 600, 800, c);
	c.x=1;c.y=c.z=0;
	triangle(350, 700, 450, 700, 400, 650, c);
	
	// glEnd();
	glFlush();
}
 
void myInit() {
	glClearColor(0.0, 0.0, 0.0, 0);
	glColor3f(0, 0, 0);
	glPointSize(4);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1920, 1080, 0);
}
 
 
 
int main(int argv, char** argc) {
	glutInit(&argv, argc);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1920, 1080);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("sadak.cpp");
	myInit();
	glutDisplayFunc(display);
	//Timer(0);
	glutMainLoop();
}