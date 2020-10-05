#include<iostream>
#include<math.h>
#include<glut.h>
using namespace std;
GLdouble X1, Y1, X2, Y2;

void LineBres(void)
{
glClear(GL_COLOR_BUFFER_BIT);
int dx = abs (X1-X2), dy = abs (Y1 - Y2);
int p = 2 * dy - dx;
int twoDy = 2* dy, twoDyDx = 2 * (dy - dx);
int x, y, xEnd;

if (X1 > X2)
{
x = X2;
y = Y2;
xEnd = X1;
}
else
{
x=X1;
y = Y1;
xEnd = X2;
}
glBegin (GL_POINTS);
glVertex2d(x,y);
while (x < xEnd)
{
	x++;
	if(p<0)

{
	p+=twoDy;
}
else
{
	y++;
	p+=twoDyDx;
}
glVertex2d (x, y);
}
glEnd ();
glFlush ();
}
void Init()
{
glViewport(0,0,640,480);
glMatrixMode (GL_PROJECTION);
glLoadIdentity(); 
gluOrtho2D(0,640,0,480);
}
int main(int argc, char **argv)
{
cout<<"Enter TwO Points for Draw Linehresenham: \n";
cout<"\n Enter Point( X1 , YI) :";
cin>>X1>>Y1;
cout<"\nEnter Point 2( X2, Y2):";
cin>>X2>>Y2;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(640, 480);
glutInitWindowPosition(0,0);
glutCreateWindow("Bresenham");
Init();
glutDisplayFunc(LineBres);
glutMainLoop();
return 0;
}
