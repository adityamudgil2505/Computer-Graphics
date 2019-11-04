// Writing name in hindi language
#include <GLUT/glut.h>
//#include <GLUT/glu.h>
#include <stdio.h>
#include <iostream>
 
int x1, y1, x2, y2,x3,y3,x4,y4;
 
void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}
 
void draw_pixel(int x, int y) {
	glPointSize(2.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
 
void drawLine(int x1, int x2, int y1, int y2)
{
	glPointSize(2.0);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2i(x1,y1);
	glVertex2i(x2,y2);
	glEnd();
}
void drawCurve() {
	double u,x,y;
	draw_pixel(x1, y1);
	draw_pixel(x4, y4);
	for(u=0.01;u<=1;u+=0.01)
	{
		x = (1-u) * (1-u) * (1-u) * x1 + 3 * u * (1-u) * (1-u) * x2 + 3 * u * u * (1-u) * x3 + u * u * u * x4;
		y = (1-u) * (1-u) * (1-u) * y1 + 3 * u * (1-u) * (1-u) * y2 + 3 * u * u * (1-u) * y3 + u * u * u * y4;
		draw_pixel(x, y);
	}
}
 
void myDisplay() {

	drawLine(30, 210, 105, 105);	// top horizontal line bar

  // 1st character
	drawLine(35, 70, 70, 70);	// middle horizontal line 	
 	drawLine(70, 70, 105, 38);	// vertical line
 	// lower curve
 	x1=30;	y1=50;
	x2=40;	y2=20;
	x3=70;	y3=70;
	x4=30;	y4=70;
	drawCurve();
	// upper curve
	x1=30;	y1=70;
	x2=70;	y2=70;
	x3=40;	y3=130;
	x4=30;	y4=90;
	drawCurve();
  drawLine(80, 80, 105, 38); // 2nd vertical line
 
  // 2nd Charcter
	drawLine(90, 90, 105, 38); // 3rd vertical line
	x1=90;	y1=105;
	x2=90;	y2=160;
	x3=130;	y3=160;
	x4=130;	y4=105;
	drawCurve();
	drawLine(130, 130, 105, 80);
	x1=130;	y1=80;
	x2=90;	y2=90;
	x3=90;	y3=50;
	x4=130;	y4=50;
	drawLine(130, 130, 50, 38);
	drawCurve();
	
 
	// 3rd character (Partial character)
	drawLine(150, 150, 60, 38);
	x1=150;	y1=60;
	x2=150;	y2=70;
	x3=162;	y3=70;
	x4=172;	y4=70;
	drawCurve();
	drawLine(172, 160, 70, 70);

	// 4th character
	x1=160;	y1=95;
	x2=160;	y2=110;
	x3=170;	y3=110;
	x4=170;	y4=85;
	drawCurve();
	x1=170;	y1=85;
	x2=170;	y2=60;
	x3=190;	y3=60;
	x4=190;	y4=95;
	drawCurve();
	drawLine(190, 190, 105, 38);
	drawLine(200, 200, 105, 38);
	glFlush();
}
 
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Cubic Bezier Curve");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
// g++ bezierCurve.cpp -framework OpenGL -framework GLUT
// ./a.out