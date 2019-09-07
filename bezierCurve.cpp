// Writing name in hindi language
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
 
int x1, y1, x2, y2,x3,y3,x4,y4;
 
void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}
 
void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
 
void drawP(int x1, int x2, int y1, int y2)
{
	glPointSize(1.0);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2i(x1,y1);
	glVertex2i(x2,y2);	
	glEnd();
}
void draw_curve() {	
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
  // 1st character
	drawP(35, 70, 70, 70);	// middle horizontal line
 	drawP(30, 180, 105, 105);	// top horizontal line bar
 	drawP(70, 70, 105, 38);	// vertical line
 	// lower curve
 	x1=30;	y1=50;
	x2=40;	y2=20;
	x3=70;	y3=70;
	x4=30;	y4=70;
	draw_curve();
	// upper curve
	x1=30;	y1=70;
	x2=70;	y2=70;
	x3=40;	y3=130;
	x4=30;	y4=90;
	draw_curve();
  drawP(80, 80, 105, 38); // 2nd vertical line
 
  // 2nd Charcter
	drawP(90, 90, 105, 38); // 3rd vertical line
	x1=90;	y1=105;
	x2=90;	y2=160;
	x3=130;	y3=160;
	x4=130;	y4=105;
	draw_curve();
	drawP(130, 130, 105, 80);
	x1=130;	y1=80;
	x2=90;	y2=90;
	x3=90;	y3=50;
	x4=130;	y4=50;
	drawP(130, 130, 50, 38);
	draw_curve();
 
 
	// 3rd character
	drawP(10, 180, 50, 38);
	drawP(180, 200, 50, 50);
	glFlush();
}
 
int main(int argc, char **argv) {
 
	printf("Enter (x1, y1, x2, y2,x3,y3,x4,y4)\n");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Cubic Bezier Curve");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}