#include <windows.h>
#include <GL/glut.h> 


void Initialize()
{
	glClearColor(0.4, 0.4, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800, 0.0, 500);
}

struct Point
{
	int X;
	int Y;
	Point(int x, int y)
	{
		X = x; Y = y;
	}

};
int angle = 1;

void WriteText(int x, int y, char* string)
{
	int len, i;

	glRasterPos2f(x, y);
	len = int(strlen(string));
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

Point Vertex[]
{ Point(294, 344) ,
Point(390, 277),
Point(344, 166),
Point(242, 166),
Point(204, 278), };

void DrawStar()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(4);
	glEnable(GL_LINE_SMOOTH);
	glColor3f(1, 1, 0.2);
	glBegin(GL_LINE_LOOP);
	glVertex2i(0, 0); //1 294 344
	glVertex2i(30, -60);
	glVertex2i(96, -67);//2
	glVertex2i(49, -114);
	glVertex2i(50, -178);//3
	glVertex2i(3, -132);
	glVertex2i(-52, -178);//4
	glVertex2i(-42, -112);
	glVertex2i(-90, -66);//5
	glVertex2i(-27, -59);
	glEnd();
	glLineWidth(1);
	glColor3f(0.0, 0.0, 0.0);
}

void DrawFirstButton()
{
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2i(788, 473);
	glVertex2i(674, 473);
	glVertex2i(674, 436);
	glVertex2i(788, 436);
	glEnd();
	glColor3f(0.1, 0.1, 0.1);
	WriteText(695, 445, "First V");
}

void DrawSecondButton()
{
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2i(788, 413);
	glVertex2i(674, 413);
	glVertex2i(674, 376);
	glVertex2i(788, 376);
	glEnd();
	glColor3f(0.1, 0.1, 0.1);
	WriteText(685, 385, "Second V");
}

void DrawThirdButton()
{
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2i(788, 353);
	glVertex2i(674, 353);
	glVertex2i(674, 316);
	glVertex2i(788, 316);
	glEnd();
	glColor3f(0.1, 0.1, 0.1);
	WriteText(695, 325, "Third V");
}

void DrawFourthButton()
{
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2i(788, 293);
	glVertex2i(674, 293);
	glVertex2i(674, 256);
	glVertex2i(788, 256);
	glEnd();
	glColor3f(0.1, 0.1, 0.1);
	WriteText(685, 265, "Fourth V");
}

void DrawFifthButton()
{
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2i(788, 233);
	glVertex2i(674, 233);
	glVertex2i(674, 196);
	glVertex2i(788, 196);
	glEnd();
	glColor3f(0.1, 0.1, 0.1);
	WriteText(695, 205, "Fifth V");
}

int currentVertex = 0;
float scaleX = 0.0;
float scaleY = 0;
float scaleStep = 0.1;

void Scale()
{
	if (scaleX >= 1 || scaleX <= -1) scaleStep = -scaleStep;
	scaleX += scaleStep;
	glScalef(scaleX, 1, 1);
}

void DrawVertexes()
{
	glPointSize(5);
	glColor3f(0.2, 1, 0.2);
	glBegin(GL_POINTS);
	glVertex2i(Vertex[0].X, Vertex[0].Y);
	glVertex2i(Vertex[1].X, Vertex[1].Y);
	glVertex2i(Vertex[2].X, Vertex[2].Y);
	glVertex2i(Vertex[3].X, Vertex[3].Y);
	glVertex2i(Vertex[4].X, Vertex[4].Y);
	glEnd();
	glPointSize(1);
}

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslated(Vertex[currentVertex].X, Vertex[currentVertex].Y, 1);
	glRotatef(angle, 0, 0, 1);
	Scale();
	DrawStar();
	glPopMatrix();
	DrawVertexes();
	DrawFirstButton();
	DrawSecondButton();
	DrawThirdButton();
	DrawFourthButton();
	DrawFifthButton();
	glFlush();
}

void mouseFunc(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON &&state == GLUT_UP)
	{
		if (x > 694 && x < 788) {
			if (y < 500 - 436 && y >500 - 473)
				currentVertex = 0;
			if (y < 500 - 376 && y >500 - 414)
				currentVertex = 1;
			if (y < 500 - 316 && y >500 - 353)
				currentVertex = 2;
			if (y < 500 - 256 && y >500 - 293)
				currentVertex = 3;
			if (y < 500 - 196 && y >500 - 233)
				currentVertex = 4;
		}
		Draw();
	}
}

void Keyboard(unsigned char key, int x, int y)
{

	if (key == 'r')
	{
		Draw();
	}
	if (key == 'u')
	{
		Draw();
	}
}

void winReshapeFcn(GLint width, GLint height)
{

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluOrtho2D(0.0, GLdouble(width), 0.0, GLdouble(height));

	glClear(GL_COLOR_BUFFER_BIT);    // ќчищенн¤ в≥кна

}


void timerFunc(int param)
{
	angle += 1;
	Draw();
	glutTimerFunc(100, timerFunc, 0);
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rotating star");
	Initialize();
	
	glutDisplayFunc(Draw);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(1, timerFunc, 1);
	glutMouseFunc(mouseFunc);
	glutMainLoop();

}