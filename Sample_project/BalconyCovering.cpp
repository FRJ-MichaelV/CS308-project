#include<stdio.h>
#include <stdlib.h>    
#include<GL/glut.h>
#include<iostream>
#include "BalconyCovering.h"

void drawSideWall() {
	glColor3f(0.8, 0.6, 0.5);
	glBegin(GL_QUADS);
	glVertex3f(0.5, 0, 0);
	glVertex3f(-0.5, 0, 0);
	glVertex3f(-0.5, 0.25, -0.5);
	glVertex3f(0.5, 0.25, -0.5);

	glVertex3f(-0.5, 0.25, -0.5);
	glVertex3f(0.5, 0.25, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);

	glVertex3f(0.5, 0, 0);
	glVertex3f(-0.5, 0, 0);
	glVertex3f(-0.5, -0.5, 0);
	glVertex3f(0.5, -0.5, 0);

	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0);
	glVertex3f(0.5, -0.5, 0);

	glVertex3f(-0.5, 0, 0);
	glVertex3f(-0.5, 0.25, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0);

	glVertex3f(0.5, 0, 0);
	glVertex3f(0.5, 0.25, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0);
	glEnd();
}

void drawFrontCovering() {
	//front door frame
	glPushMatrix();
	glColor3f(1, 1, 0.8);
	glTranslatef(0, 1, -3);
	glScalef(3, 1, 0.05);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 0.8);
	glTranslatef(2.5, 0, -3);
	glScalef(2, 3, 0.05);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 0.8);
	glTranslatef(-2.5, 0, -3);
	glScalef(2, 3, 0.05);
	glutSolidCube(1);
	glPopMatrix();

	//left balcony covering
	//front left side wall
	glPushMatrix();
	glTranslatef(-3.5, 0.47, 1);
	glScalef(0.1, 4, 8);
	drawSideWall();
	glPopMatrix();

	//front left balcony wall
	glPushMatrix();
	glColor3f(1, 1, 0.8);
	glTranslatef(-4.5, -0.8, 1);
	glScalef(2, 2.5, 0.05);
	glutSolidCube(1);
	glPopMatrix();

	//front left step wall
	glPushMatrix();
	glTranslatef(-5.45, -0.4, 3);
	glScalef(0.1, 3.3, 4);
	drawSideWall();
	glPopMatrix();

	//front balcony left step wall
	glPushMatrix();
	glTranslatef(-6.55, 0.8, 3);
	glScalef(0.1, 5, 16);
	drawSideWall();
	glPopMatrix();

	//left balcony step wall
	glPushMatrix();
	glTranslatef(-11.5, 0.8, 1);
	glScalef(0.1, 5, 12);
	drawSideWall();
	glPopMatrix();

	//left balcony cover
	glPushMatrix();
	glColor3f(1, 1, 0.8);
	glTranslatef(-14, -0.8, 1);
	glScalef(5, 2.5, 0.05);
	glutSolidCube(1);
	glPopMatrix();

	//left balcony step side wall
	glPushMatrix();
	glTranslatef(-16.45, -0.4, 3);
	glScalef(0.1, 3.3, 4);
	drawSideWall();
	glPopMatrix();

	//left balcony wall
	glPushMatrix();
	glColor3f(1, 1, 0.8);
	glTranslatef(-9, 0, -5);
	glScalef(5, 4, 0.05);
	glutSolidCube(1);
	glPopMatrix();

	//right balcony covering
	//front right side wall
	glPushMatrix();
	glTranslatef(3.5, 0.47, 1);
	glScalef(0.1, 4, 8);
	drawSideWall();
	glPopMatrix();

	//front right balcony wall
	glPushMatrix();
	glColor3f(1, 1, 0.8);
	glTranslatef(4.5, -0.8, 1);
	glScalef(2, 2.5, 0.05);
	glutSolidCube(1);
	glPopMatrix();

	//front right step wall
	glPushMatrix();
	glTranslatef(5.45, -0.4, 3);
	glScalef(0.1, 3.3, 4);
	drawSideWall();
	glPopMatrix();

	//front balcony right step wall
	glPushMatrix();
	glTranslatef(6.55, 0.8, 3);
	glScalef(0.1, 5, 16);
	drawSideWall();
	glPopMatrix();

	//right balcony step wall
	glPushMatrix();
	glTranslatef(11.5, 0.8, 1);
	glScalef(0.1, 5, 12);
	drawSideWall();
	glPopMatrix();

	//right balcony cover
	glPushMatrix();
	glColor3f(1, 1, 0.8);
	glTranslatef(14, -0.8, 1);
	glScalef(5, 2.5, 0.05);
	glutSolidCube(1);
	glPopMatrix();

	//right balcony step side wall
	glPushMatrix();
	glTranslatef(16.45, -0.4, 3);
	glScalef(0.1, 3.3, 4);
	drawSideWall();
	glPopMatrix();

	//right balcony wall
	glPushMatrix();
	glColor3f(1, 1, 0.8);
	glTranslatef(-9, 0, -5);
	glScalef(5, 4, 0.05);
	glutSolidCube(1);
	glPopMatrix();
}