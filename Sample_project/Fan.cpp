#include<stdio.h>
#include <stdlib.h>    
#include<GL/glut.h>
#include<iostream>
#include "Fan.h"

void drawCylinder2(GLfloat radius, GLfloat height) {
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic, radius, radius, height, 100, 100);
}

void drawFan() {
	glPushMatrix();
	glColor3f(1, 1, 1);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(1, 1.2, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glRotatef(-90, 1, 0, 0);
	glutSolidTorus(0.2, 1, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 0);
	glutSolidSphere(0.8, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glRotatef(-90, 1, 0, 0);
	drawCylinder2(0.2, 2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0, 0, 1.2);
	glScalef(1, 0.01, 4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(1.1, 0, -0.8);
	glRotatef(-60, 0, 1, 0);
	glScalef(1, 0.01, 4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(-1.1, 0, -0.8);
	glRotatef(60, 0, 1, 0);
	glScalef(1, 0.01, 4);
	glutSolidCube(1);
	glPopMatrix();
}
