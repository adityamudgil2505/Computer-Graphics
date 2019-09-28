#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>
#include<string>
using namespace std;
 
int globalX, globalY;
 
// To create a single point
void point(int px, int py){
	glColor3f(0.0,0.0,1.0);
 	glBegin(GL_POINTS);
 	glVertex2f(px,py);
 	glEnd();
}
 
// To create a line from 2 points
void line(int x1, int x2, int y1, int y2){
	glBegin(GL_LINE);
	glVertex3f(x1,y1,0);
	glVertex3f(x2,y2,0);
	glEnd();
}
 
// To create a quadrilatral from 4 points
void wall(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2,GLfloat x3,GLfloat y3,GLfloat x4,GLfloat y4){	
	glBegin(GL_POLYGON);
	glVertex3f(x1,y1,0);
	glVertex3f(x2,y2,0);
	glVertex3f(x3,y3,0);
	glVertex3f(x4,y4,0);
  	glEnd();
}
 
// To draw bezier curve
void draw_curve(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4){ 
    double u,x,y;
    point(x1, y1);
    point(x4, y4);
    for(u=0.01;u<=1;u+=0.01)
    {
        x = (1-u) * (1-u) * (1-u) * x1 + 3 * u * (1-u) * (1-u) * x2 + 3 * u * u * (1-u) * x3 + u * u * u * x4;
        y = (1-u) * (1-u) * (1-u) * y1 + 3 * u * (1-u) * (1-u) * y2 + 3 * u * u * (1-u) * y3 + u * u * u * y4;
        point(x, y);
    }
}
 
// To draw circle
void plot_point(int x, int y, int xc, int yc){
    glBegin(GL_POINTS);
    glVertex2i(xc+x, yc+y);
    glVertex2i(xc+x, yc-y);
    glVertex2i(xc+y, yc+x);
    glVertex2i(xc+y, yc-x);
    glVertex2i(xc-x, yc-y);
    glVertex2i(xc-y, yc-x);
    glVertex2i(xc-x, yc+y);
    glVertex2i(xc-y, yc+x);
    glEnd();
}
 
void draw_cicle(int xc, int yc, int r){
    int x=0, y=r;
    float pk=(50.0/40.0)-r;
    plot_point(x,y, xc, yc);
    int k;
    while(x < y)
    {
        x = x + 1;
        if(pk < 0)
          pk = pk + 2*x+1;
        else
        {
          y = y - 1;
          pk = pk + 2*(x - y) + 1;
        }
        plot_point(x,y, xc, yc);
    }
    glFlush();
}
 
// To display a string
void drawstring(int x, int y, string str,void *font=GLUT_BITMAP_TIMES_ROMAN_24)
{
      int len=0, i;
       glRasterPos2f(x,y);
       while(str[len]!='\0')	len++;
       for (i = 0; i < len; i++)
		{
         glutBitmapCharacter(font,str[i]);
		}
}
 
void myinit(){	
	glMatrixMode(GL_PROJECTION);
  	glLoadIdentity();
  	glPointSize(10.0);	// to display 10 time of default
  	glMatrixMode(GL_MODELVIEW);
  	glClearColor(0.0,0.0,0.0,0.0);
}
 
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
 
	// first item to display
	glColor3f(1,0,0);		// give color to this item
	drawstring(globalX, globalY, "Hello World");	// function to create shape
	glutPostRedisplay();	// to update the display
 
 
	// second item to display
	glColor3f(0,1,0);
	point(50, 50);
	glutPostRedisplay();
 
 
	// to show output to the screen
	glFlush();
}
 
void callbackReshape(int w, int h){
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		gluOrtho2D(45.0,135.0,-2.0*(GLfloat)h/(GLfloat)w,180.0*(GLfloat)h/(GLfloat)w);
	else
		gluOrtho2D(-45.0*(GLfloat)w/(GLfloat)h,135.0*(GLfloat)w/(GLfloat)h,-2.0,180.0);
  	glMatrixMode(GL_MODELVIEW);
  	glutPostRedisplay();
}
 
void SpecialKey(int key, int x, int y)
{
  switch (key){
 
	case GLUT_KEY_UP:
		globalY+=50;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		globalY-=50;
		glutPostRedisplay();
		break;
 
	case GLUT_KEY_LEFT:
		globalX-=50;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		globalX+=50;
		glutPostRedisplay();
		break;
  }
}
 
int main(int argc, char** argv){
	globalX = globalY = 10;
	glutInit(&argc, argv);
  	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	// set initial display mode
  	glutInitWindowSize(700,500);	// set window size
  	glutCreateWindow("Tutorial");	// give name to the window
  	glutSpecialFunc(SpecialKey);	// keyword will work
  	glutReshapeFunc(callbackReshape); // reshape callback is triggered when a window is reshaped.
	glutDisplayFunc(display);	//	glutDisplayFunc is called whenever your window must be redrawn. This includes the time when one calls glutPostRedisplay
  	myinit();	// intialize window display
  	glutMainLoop();
  	return 0;
}