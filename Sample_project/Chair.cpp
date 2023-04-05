#include<stdio.h>
#include <stdlib.h>    
#include<GL/glut.h>
#include<iostream>
#include "Chair.h"

void drawCylinder(GLfloat radius, GLfloat height) {
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic, radius, radius, height, 100, 100);
	glutSolidSphere(radius, 40, 40);
	glTranslatef(0, 0, height);
	glutSolidSphere(radius, 40, 40);
}

void drawHandle() {
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glScalef(0.1, 0.1, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0, 0, -0.5);
	glutSolidSphere(0.05, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0, 0, 0.5);
	glutSolidSphere(0.05, 40, 40);
	glPopMatrix();
}

void drawSupport() {
	glPushMatrix();
	glColor3f(0, 0, 0);
	glutSolidCone(1, 2, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, 0, 1.5);
	glutSolidCube(1);
	glPopMatrix();
}

void drawArmSupport() {
	glPushMatrix();
	glTranslatef(0.65, -0.04, 0.5);
	glRotatef(90, 1, 0, 0);
	glScalef(0.1, 0.5, 0.3);
	drawSupport();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.4, 0.4, 0.4);
	glTranslatef(0.65, -0.62, 0.5);
	glScalef(0.2, 0.05, 0.7);
	glutSolidCube(1);
	glPopMatrix();
}

void drawChair() {
	glPushMatrix();
	glColor3f(0.5, 0.1, 1);
	glTranslatef(0, -0.5, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(2, 6, 1);
	drawCylinder(0.1, 1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.4, 1);
	glTranslatef(-0.5, 0, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(-30, 0, 0, 1);
	glScalef(2, 6, 1);
	drawCylinder(0.1, 1);
	glPopMatrix();

	//draw Handles
	glPushMatrix();
	glTranslatef(-0.65, 0, 0.5);
	drawHandle();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.65, 0, 0.5);
	drawHandle();
	glPopMatrix();

	//side arm supports
	glPushMatrix();
	glScalef(1, 1.2, 1);
	drawArmSupport();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.3, 0, 0);
	glScalef(1, 1.2, 1);
	drawArmSupport();
	glPopMatrix();
}

