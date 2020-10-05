#include <iostream>
#include<glut.h>
using namespace std;
GLdouble x1, x2, y1, y2;

void Lineintercept(void)
{
	GLdouble dx=x2-x1;
	GLdouble dy=y2-y1;
	GLdouble m=dy/dx;
	GLdouble b=y1-m*x1;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	if(m<1)
		{
			for(GLdouble x=x1; x<=x2; x++)
			{
				GLdouble y= m*x+b;
				glVertex2d(x,y);
			}
		}
	else
	{
		for(GLdouble y=y1; y<=y2; y++)
		{
			GLdouble x=(1/m)*y+b;
			glVertex2d(x,y);
		}
	}
	glEnd();
	glFlush();
}

int init()
{
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,640,0,480);
}

int main(int argc,char** argv)
{
	cout<<"Enter two values to draw lineslopeintercept\n";
	cout<<"Enter the value of x1 and y1 for point 1 \n";
	cin>>x1>>y1;
	cout<<"Enter the value of x2 and y2 for point 1\n";
	cin>>x2>>y2;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("apurva Lineslopeintercept");
	init();
	glutDisplayFunc(Lineintercept);
	glutMainLoop();
}
