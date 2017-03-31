#define _CRT_SECURE_NO_WARNINGS
/*
* OGL02Animation.cpp: 3D Shapes with animation
*/
#include <fstream>
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <GL/SOIL.h>


/* Global variables */
char title[] = "3D Shapes with animation";
GLfloat anglePyramid = 0.0f;  // Rotational angle for pyramid [NEW]
int refreshMills = 15;        // refresh interval in milliseconds [NEW]


GLuint loadBMP_custom(const char * imagepath);

GLuint LoadTexture(const char * filename)
{

	GLuint texture;

	int width, height;

	unsigned char * data;

	FILE * file;

	file = fopen(filename, "rb");

	if (file == NULL) return 0;
	width = 512;
	height = 512;
	data = (unsigned char *)malloc(width * height * 3);
	//int size = fseek(file,);
	fread(data, width * height * 3, 1, file);
	fclose(file);

	for (int i = 0; i < width * height; ++i)
	{
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];

		data[index] = R;
		data[index + 2] = B;

	}


	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);


	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
	free(data);

	return texture;
}
GLuint texture = LoadTexture("texture.bmp");

							  /* Initialize OpenGL Graphics */
void initGL() {
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);  // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

/* Handler for window-repaint event. Called back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix


			  // Render a pyramid consists of 4 triangles
	glLoadIdentity();                  // Reset the model-view matrix
	glTranslatef(0.0f, 0.0f, -6.0f);  // Move left and into the screen
	glRotatef(anglePyramid, 1.0f, 1.0f, 0.0f);  // Rotate about the (1,1,0)-axis [NEW]


	glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
									 // Front
	glColor3f(0.7f, 0.2f, 0.2f);     // Red
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	// Right
	glColor3f(0.2f, 0.7f, 0.2f);     // Red
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	// Back
	glColor3f(0.2f, 0.2f, 0.7f);     // Red
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	// Left
	glColor3f(0.2f, 0.7f, 0.7f);       // Red
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();   // Done drawing the pyramid

	//Bottom
	glEnable(GL_TEXTURE_2D);

	
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glColor3f(0.5f, 0.5f, 0.0f);
	glBegin(GL_QUADS);
	    // Gray
	glTexCoord2d(0.0, 0.0);	glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2d(1.0, 0.0);	glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2d(1.0, 1.0);	glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2d(0.0, 1.0);	glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();

	//glClearColor(0.5f, 0.5f, 0.5f);      // Будем очищать экран, заполняя его цветом тумана. ( Изменено )

	glEnable(GL_FOG);                       // Включает туман (GL_FOG)
	glFogi(GL_FOG_MODE, GL_LINEAR);// Выбираем тип тумана
	GLfloat fogColor[4] = { 0.5f, 0.5f, 0.5f, 1.0f }; // Цвет тумана
	glFogfv(GL_FOG_COLOR, fogColor);        // Устанавливаем цвет тумана
	glFogf(GL_FOG_DENSITY, 0.8f);          // Насколько густым будет туман
	glHint(GL_FOG_HINT, GL_DONT_CARE);      // Вспомогательная установка тумана
	glFogf(GL_FOG_START, 5.3f);             // Глубина, с которой начинается туман
	glFogf(GL_FOG_END, 6.5f);               // Глубина, где туман заканчивается.
	
	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

						// Update the rotational angle after each refresh [NEW]
	anglePyramid += 1.2f;
}

/* Called back when timer expired [NEW] */
void timer(int value) {
	glutPostRedisplay();      // Post re-paint request to activate display()
	glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

/* Handler for window re-size event. Called back when the window first appears and
whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
											   // Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset
								  // Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(640, 480);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow(title);          // Create window with the given title
	//texture
	
	texture = LoadTexture("texture.bmp");
	//texture end


	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);       // Register callback handler for window re-size event
	initGL();                       // Our own OpenGL initialization
	glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]
	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}

GLuint loadBMP_custom(const char * imagepath)
{
	unsigned int dataPos; // Смещение данных в файле (позиция данных) 
	unsigned int width, height; unsigned int imageSize; // Размер изображения = Ширина * Высота * 3 // RGB-данные, полученные из файла 
	unsigned char * data;


	FILE * file = fopen(imagepath, "rb"); if (!file) { printf("Image can not be opened"); return 0; }
	char header[54];
	if (fread(header, 1, 54, file) != 54) { // Если мы прочитали меньше 54 байт, значит возникла проблема 
		printf("Incorrect BMP file"); return false; }

	if (header[0] != 'B' || header[1] != 'M') { printf("Incorrecrt BMP file"); return 0; }

	// Читаем необходимые данные 
	dataPos = (int)&(header[0x0A]); // Смещение данных изображения в файле 
	imageSize = (int)&(header[0x22]); // Размер изображения в байтах
	width = (int)&(header[0x12]); // Ширина 
	height = (int)&(header[0x16]);
	if (imageSize == 0) imageSize = width*height*3; // Ширину * Высоту * 3, где 3 - 3 компоненты цвета (RGB) 
	if (dataPos==0) dataPos=54; 
	data = new unsigned char[imageSize];

	// Считываем данные из файла в буфер 
	fread(data,1,imageSize,file);

	// Закрываем файл, так как больше он нам не нужен 
	fclose(file);

	GLuint textureID; glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	











}