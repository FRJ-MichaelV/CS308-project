#include <stdlib.h>    
#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include "Chair.h"
#include "ChairGroup.h"
#include "BottomLayer.h"
#include "BalconyCovering.h"
#include "Balcony.h"
#include "Fan.h"
#define pi 3.1415927

const double PI = 3.141592654;
GLfloat camY = 0.0, camZ = 0.0, sceY = 0.0, objY = 0.0, micZ = 0.0, micX = 0.0, doorX = 0.0;

void init() {
	glClearColor(1, 0.9, 0.9, 1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_NORMALIZE);
}

void drawGrid(int gridspan) {
	GLfloat step = 1.0f;
	GLint line;

	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	for (line = -gridspan; line <= gridspan; line += step) {
		glVertex3f(-gridspan, -0.4, line);
		glVertex3f(gridspan, -0.4, line);

		glVertex3f(line, -0.4, -gridspan);
		glVertex3f(line, -0.4, gridspan);
	}
	glEnd();
}

void drawAxes() {
	glBegin(GL_LINES);

	glColor3f(1, 0, 0);
	glVertex3f(-200, 0, 0);
	glVertex3f(200, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, -200, 0);
	glVertex3f(0, 200, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, -200);
	glVertex3f(0, 0, 200);

	glEnd();
}

void keyboardSpecial(int key, int x, int y) {
	if (key == GLUT_KEY_UP) camY += 3;
	if (key == GLUT_KEY_DOWN) camY -= 3;
	if (key == GLUT_KEY_LEFT) sceY -= 3;
	if (key == GLUT_KEY_RIGHT) sceY += 3;

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 'z') camZ += 1;
	if (key == 'Z') camZ -= 1;

	if (key == '1') glEnable(GL_LIGHT0);
	if (key == '!') glDisable(GL_LIGHT0);

	if (key == '2') glEnable(GL_LIGHT1);
	if (key == '@') glDisable(GL_LIGHT1);

	if (key == 'w') micZ += 1;
	if (key == 's') micZ -= 1;

	if (key == 'a') micX -= 1;
	if (key == 'd') micX += 1;

	if (key == 'o') doorX -= 1;
	if (key == 'c') doorX += 1;
	
	glutPostRedisplay();
}

void drawFanGroup() {
	glPushMatrix();
	glTranslatef(0, 9.5, 0);
	glRotatef(objY, 0, 1, 0);
	drawFan();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 9.5, 10);
	glRotatef(objY, 0, 1, 0);
	drawFan();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 9.5, 20);
	glRotatef(objY, 0, 1, 0);
	drawFan();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 9.5, 30);
	glRotatef(objY, 0, 1, 0);
	drawFan();
	glPopMatrix();
}

void drawFanSet() {
	glPushMatrix();
	drawFanGroup();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10, 0, 0);
	drawFanGroup();
	glPopMatrix();
}

void drawOpening() {
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(-19, -1.4, -26.52);
	glBegin(GL_POLYGON);
	glVertex3f(17.5, 0, 17.5);
	glVertex3f(17.5, 13, 17.5);
	glVertex3f(12.1, 13, 17.5);
	glVertex3f(1.5, 6, 17.5);
	glVertex3f(1.5, 0, 17.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0, -1.4, -26.52);
	glBegin(GL_POLYGON);
	glVertex3f(17.5, 0, 17.5);
	glVertex3f(17.5, 13, 17.5);
	glVertex3f(1.5, 13, 17.5);
	glVertex3f(1.5, 0, 17.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(-16, -1.4, -26.52);
	glBegin(GL_POLYGON);
	glVertex3f(17.5, 2, 17.5);
	glVertex3f(17.5, 13, 17.5);
	glVertex3f(14.5, 13, 17.5);
	glVertex3f(14.5, 2, 17.5);
	glEnd();
	glPopMatrix();	
}

void drawWalls() {
	//gray walls left and right
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.8);
	glTranslatef(-17.5, 0.1, 13.5);
	glScalef(0.02, 3, 45);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.8);
	glTranslatef(17.5, 0.1, 13.5);
	glScalef(0.02, 3, 45);
	glutSolidCube(1);
	glPopMatrix();

	//brown walls right
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.9);
	glTranslatef(17.5, 3.1, 28.5);
	glScalef(0.02, 3, 15);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.9);
	glTranslatef(17.5, 4.1, 13.5);
	glScalef(0.02, 5, 15);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.9);
	glTranslatef(17.5, 5.1, -1.5);
	glScalef(0.02, 7, 15);
	glutSolidCube(1);
	glPopMatrix();

	//brown walls left
	glColor3f(0.7, 0.7, 0.9);
	glTranslatef(-17.5, 3.1, 13.5);
	glScalef(0.02, 3, 45);
	glutSolidCube(1);
	glPopMatrix();

	//butter walls right
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(17.5, 10.1, -1.5);
	glScalef(0.02, 3, 15);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(17.5, 9.1, 13.5);
	glScalef(0.02, 5, 15);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(17.5, 8.1, 28.5);
	glScalef(0.02, 7, 15);
	glutSolidCube(1);
	glPopMatrix();

	//main wall right red
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(17.55, 5, 13.5);
	glScalef(0.1, 13, 45);
	glutSolidCube(1);
	glPopMatrix();

	//main wall left red
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(-17.55, 1.5, 13.5);
	glScalef(0.1, 6, 45);
	glutSolidCube(1);
	glPopMatrix();

	//stage wall
	glPushMatrix();
	glColor3f(1, 0.9, 1);
	glTranslatef(0, -1.4, 18.5);
	glBegin(GL_POLYGON);
	glVertex3f(17.5, 0, 17.5);
	glVertex3f(17.5, 13, 17.5);
	glVertex3f(-6.9, 13, 17.5);
	glVertex3f(-17.5, 6, 17.5);
	glVertex3f(-17.5, 0, 17.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	drawOpening();
	glPopMatrix();

	//draw floor
	glPushMatrix();
	glColor3f(0.4, 0.4, 0.5);
	glTranslatef(0, -1.8, 13);
	glScalef(37, 0.6, 47);
	glutSolidCube(1);
	glPopMatrix();
}

void drawCircle(double r) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 50; d++) {
		double angle = 2 * pi / 50 * d;
		glVertex2d(r * cos(angle), r * sin(angle));
	}
	glEnd();
}

void drawCylinder3(GLfloat radius, GLfloat height) {
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic, radius, radius, height, 100, 100);
	drawCircle(radius);
	glTranslatef(0, 0, height);
	drawCircle(radius);
}

void drawMic() {
	glPushMatrix();
	glColor3f(0, 0, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.1, 0.8, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glutSolidSphere(0.13, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, 0.1, 0);
	glRotatef(-90, 1, 0, 0);
	drawCylinder3(0.05, 0.5);
	glPopMatrix();
}

void drawMicStand() {
	glPushMatrix();
	glTranslatef(0, 4.1, 0.3);
	glRotatef(-105, 1, 0, 0);
	drawMic();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, 2, 0);
	glRotatef(-90, 1, 0, 0);
	drawCylinder3(0.05, 2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glRotatef(-90, 1, 0, 0);
	drawCylinder3(0.1, 2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glRotatef(-90, 1, 0, 0);
	drawCylinder3(0.8, 0.1);
	glPopMatrix();
}

void drawStage() {
	//steps
	glPushMatrix();
	glColor3f(0.8, 0, 0);
	glTranslatef(0, 0.25, 0);
	glScalef(29, 0.25, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8, 0, 0);
	glTranslatef(0, 0.5, 2);
	glScalef(29, 0.25, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8, 0, 0);
	glTranslatef(0, 0.75, 4);
	glScalef(29, 0.25, 2);
	glutSolidCube(1);
	glPopMatrix();

	//center stage
	glPushMatrix();
	glColor3f(0.4, 0.2, 0.2);
	glTranslatef(0, 0.625, 10.75);
	glScalef(29, 1, 12);
	glutSolidCube(1);
	glPopMatrix();

	//right stage
	glPushMatrix();
	glColor3f(0.4, 0.2, 0.2);
	glTranslatef(15.5, 0.625, 7.5);
	glScalef(4, 1, 18.5);
	glutSolidCube(1);
	glPopMatrix();

	//left stage
	glPushMatrix();
	glColor3f(0.4, 0.2, 0.2);
	glTranslatef(-15.5, 0.625, 7.5);
	glScalef(4, 1, 18.5);
	glutSolidCube(1);
	glPopMatrix();

	//drawMic
	glPushMatrix();
	glTranslatef(0, 1.5, 8);
	glTranslatef(micX, 0, micZ);
	drawMicStand();
	glPopMatrix();
}

void drawRoof() {
	glPushMatrix();
	glColor3f(0.8, 0.4, 0.5);
	glTranslatef(5.6, 11.5, 13);
	glScalef(25, 0.3, 47);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8, 0.4, 0.5);
	glTranslatef(-13, 7.5, 13);
	glRotatef(33, 0, 0, 1);
	glScalef(15, 0.3, 47);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	drawFanSet();
	glPopMatrix();
}

void timer(int v) {
	objY += 20;
	glutPostRedisplay();
	glutTimerFunc(30, timer, 0);
}

void drawDoors1() {
	glPushMatrix();
	glColor3f(0.5, 0.14, 0.14);
	glTranslatef(0.76, 1.6, -21);
	glScalef(1.5, 2, 0.01);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.14, 0.14);
	glTranslatef(-0.75, 1.6, -21);
	glScalef(1.5, 2, 0.01);
	glutSolidCube(1);
	glPopMatrix();
}

void drawHall() {
	glPushMatrix();
	drawBalcony();
	glPopMatrix();

	glPushMatrix();
	drawLayer1();//from BottomLayer.h file
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.3, 19);
	drawStage();
	glPopMatrix();

	glPushMatrix();
	drawRoof();
	glPopMatrix();

	glPushMatrix();
	drawWalls();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(doorX, 0, 0);
	drawDoors1();
	glPopMatrix();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 2 + camY, -32 - camZ, 0, 0, 0, 0, 1, 0);
	glRotatef(sceY, 0, 1, 0);

	glPushMatrix();
	//drawGrid(40);
	//drawAxes();

	const GLfloat matwhite[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	//Add positioned light
	GLfloat lightPos0[] = {2.0, 2.0, 10.0, 0.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, matwhite);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	//Add directed light
	GLfloat lightPos1[] = { 2.0, 2.0, -10.0, 0.0f };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, matwhite);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

	glPushMatrix();
	glTranslatef(0, 2, -12);
	drawHall();
	glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();
}

void reshape(GLsizei w, GLsizei h) {
	if (h == 0) h = 1;
	GLfloat aspect = (GLfloat)w / (GLfloat)h;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(120, aspect, 1, 100);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(1500, 1500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("3D scene");

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboardSpecial);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(30, timer, 0);

	glutMainLoop();
}