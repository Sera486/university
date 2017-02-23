#include <windows.h>
#include <GL/glut.h> 


void Initialize()
{
	glClearColor(0.3, 0.7, 0.3, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800, 0.0, 500);
}

void WriteText(int x, int y, char* string)
{
	int len, i;

	glRasterPos2f(x, y);
	len = int(strlen(string));
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void DrawEvergreen()
{
	glColor3f(0.9, 0.9, 0.9);
	WriteText(550, 40, "Evergreen");
	glColor3f(0.7, 0.7, 0.4);
	glBegin(GL_POLYGON);
	glVertex2i(581, 92);
	glVertex2i(580, 69);
	glVertex2i(607, 68);
	glVertex2i(607, 89);
	glEnd();

	glColor3f(0.05, 0.4, 0.05);
	glBegin(GL_POLYGON);
	glVertex2i(646, 88);
	glVertex2i(539, 92);
	glVertex2i(591, 128);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(545, 118);
	glVertex2i(595, 159);
	glVertex2i(637, 116);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(598, 194);
	glVertex2i(559, 145);
	glVertex2i(638, 140);
	glEnd();
}

void DrawAppletree()
{
	glColor3f(0.9, 0.9, 0.9);
	WriteText(120, 100, "Apple tree");
	glColor3f(0.7, 0.7, 0.4);
	glBegin(GL_POLYGON);
	glVertex2i(160, 120);
	glVertex2i(160, 141);
	glVertex2i(182, 141);
	glVertex2i(182, 129);
	glVertex2i(182, 120);
	glEnd();

	glColor3f(0.05, 0.4, 0.05); 
	glBegin(GL_POLYGON);
	glVertex2i(160, 141);
	glVertex2i(150, 141);
	glVertex2i(136, 139);
	glVertex2i(123, 152);
	glVertex2i(121, 170);
	glVertex2i(123, 188);
	glVertex2i(134, 193);
	glVertex2i(147, 196);
	glVertex2i(166, 201);
	glVertex2i(179, 201);
	glVertex2i(196, 197);
	glVertex2i(210, 191);
	glVertex2i(220, 177);
	glVertex2i(220, 166);
	glVertex2i(219, 152);
	glVertex2i(211, 141);
	glVertex2i(195, 141);
	glVertex2i(182, 141);
	glEnd();
}

void DrawRoad()
{
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2i(0, 331);
	glVertex2i(0, 285);
	glVertex2i(69, 337);
	glVertex2i(97, 280);
	glVertex2i(146, 333);
	glVertex2i(168, 285);
	glVertex2i(214, 326);
	glVertex2i(244, 285);
	glVertex2i(311, 331);
	glVertex2i(326, 280);
	glVertex2i(377, 331);
	glVertex2i(432, 271);
	glVertex2i(464, 331);
	glVertex2i(479, 274);
	glVertex2i(536, 316);
	glVertex2i(567, 268);
	glVertex2i(606, 306);
	glVertex2i(654, 255);
	glVertex2i(708, 302);
	glVertex2i(742, 255);
	glVertex2i(800, 301);
	glVertex2i(800, 256);
	glEnd();
	glColor3f(0.9, 0.9, 0.9);
	WriteText(150, 290, "Road");
}

void DrawRiver()
{
	glColor3f(0.3, 0.3, 0.7);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2i(295, 0);
	glVertex2i(374, 0);
	glVertex2i(318, 78);
	glVertex2i(405, 70);
	glVertex2i(341, 134);
	glVertex2i(423, 137);
	glVertex2i(368, 194);
	glVertex2i(475, 190);
	glVertex2i(412, 233);
	glVertex2i(517, 238);
	glVertex2i(441, 281);
	glVertex2i(532, 293);
	glVertex2i(453, 331);
	glVertex2i(535, 348);
	glVertex2i(460, 376);
	glVertex2i(538, 397);
	glVertex2i(458, 425);
	glVertex2i(553, 431);
	glVertex2i(473, 465);
	glVertex2i(570, 453);
	glVertex2i(497, 488);
	glVertex2i(594, 473);
	glVertex2i(500, 503);
	glVertex2i(635, 503);
	glEnd();
	glColor3f(0.9, 0.9, 0.9);
	WriteText(350, 100, "River");
}

void DrawBridge()
{
	glColor3f(0.6, 0.6, 0.1);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2i(432, 268);
	glVertex2i(450, 334);
	glVertex2i(479, 260);
	glVertex2i(535, 320);
	glVertex2i(530, 264);
	glEnd();
}

void DrawDeleteButton()
{
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2i(788, 473);
	glVertex2i(694, 473);
	glVertex2i(694, 436);
	glVertex2i(788, 436);
	glEnd();
	glColor3f(0.1, 0.1, 0.1);
	WriteText(710,  445, "Delete");
}


void DrawUndoButton()
{
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2i(788, 414);
	glVertex2i(694, 414);
	glVertex2i(694, 376);
	glVertex2i(788, 376);
	glEnd();
	glColor3f(0.1, 0.1, 0.1);
	WriteText(710, 385, "Undo");
}
int deleteState = 0;




void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	if (deleteState < 4)
		DrawRoad();
	if (deleteState < 5)
		DrawRiver();
	if (deleteState < 3)
		DrawBridge();
	if (deleteState < 2)
		DrawEvergreen();
	if (deleteState < 1)
		DrawAppletree();
	DrawDeleteButton();
	DrawUndoButton();
	glFlush();
}

void mouseFunc(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON &&state == GLUT_UP)
	{
		if (x > 694 && x < 788 && y<500-436 && y >500- 473)
			if (deleteState<5)
				deleteState++;

		if (x > 694 && x < 788 && y<500 - 376 && y >500 - 414)
			if (deleteState>0)
				deleteState--;
		Draw();
	}
}

void Keyboard(unsigned char key, int x, int y)
{
	if (key == 'r')
	{
		if(deleteState<5)
		deleteState++;
		Draw();
	}
	if (key == 'u')
	{
		if(deleteState>0)
		deleteState--;
		Draw();
	}
}

void winReshapeFcn(GLint width, GLint height)
{

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluOrtho2D(0.0, GLdouble(width), 0.0, GLdouble(height));

	glClear(GL_COLOR_BUFFER_BIT);    // Очищення вікна

}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Road through the river");
	Initialize();
	glutDisplayFunc(Draw);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(mouseFunc);
	glutMainLoop();
	return 0;
}