#include<stdio.h>
#include <stdlib.h>    
#include<GL/glut.h>
#include<iostream>
#include "Chair.h"
#include "ChairGroup.h"
#include "BalconyCovering.h"
#include "Balcony.h"

void drawSteps() {
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(0, 1, -1);
	glutSolidCube(1);
	glPopMatrix();
}

void drawSteps1() {
	glPushMatrix();
	glScalef(1, 0.25, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.5, 2);
	glScalef(1, 0.25, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.25, 1);
	glScalef(1, 0.25, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.25, -1);
	glScalef(1, 0.25, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.5, -2);
	glScalef(1, 0.25, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.75, -3);
	glScalef(1, 0.25, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1, -4);
	glScalef(1, 0.25, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.25, -5);
	glScalef(1, 0.25, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.5, -6);
	glScalef(1, 0.25, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.75, -7);
	glScalef(1, 0.25, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 2, -8);
	glScalef(1, 0.25, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 2.25, -9);
	glScalef(1, 0.25, 1);
	glutSolidCube(1);
	glPopMatrix();
}

void drawRightBalcony() {
	//upper right 2 step balcony
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(11.5, 1.4, -8);
	glScalef(10, 0.5, -2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(11.5, 0.9, -6);
	glScalef(10, 0.5, -2);
	glutSolidCube(1);
	glPopMatrix();

	//lower right 3 step balcony
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(14, 0.4, -4);
	glScalef(5, 0.5, -2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(14, -0.1, -2);
	glScalef(5, 0.5, -2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(14, -0.6, 0);
	glScalef(5, 0.5, -2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(13.8, 2.5, -8.5);
	drawSet6();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(13.8, 2, -6.5);
	drawSet6();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15.5, 1.5, -4.5);
	drawSet3();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15.5, 1, -2.5);
	drawSet3();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15.5, 0.5, -0.5);
	drawSet3();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8, 0, 0.5);
	glTranslatef(17, -0.73, 0.5);
	drawSteps1();
	glPopMatrix();
}

void drawLeftBalcony() {
	//upper left 2 step balcony
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(-11.5, 1.4, -8);
	glScalef(10, 0.5, -2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(-11.5, 0.9, -6);
	glScalef(10, 0.5, -2);
	glutSolidCube(1);
	glPopMatrix();

	//lower left 3 step balcony
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(-14, 0.4, -4);
	glScalef(5, 0.5, -2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(-14, -0.1, -2);
	glScalef(5, 0.5, -2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(-14, -0.6, 0);
	glScalef(5, 0.5, -2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-9.2, 2.5, -8.5);
	drawSet6();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-9.2, 2, -6.5);
	drawSet6();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-12.4, 1.5, -4.5);
	drawSet3();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-12.4, 1, -2.5);
	drawSet3();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-12.4, 0.5, -0.5);
	drawSet3();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8, 0, 0.5);
	glTranslatef(-17, -0.73, 0.5);
	drawSteps1();
	glPopMatrix();
}

void drawBalcony() {
	//left 2 step balcony
	glPushMatrix();
	glTranslatef(-4.5, -1.5, 0);
	glScalef(2, 0.5, 2);
	drawSteps();
	glPopMatrix();

	//right 2 step balcony
	glPushMatrix();
	glTranslatef(4.5, -1.5, 0);
	glScalef(2, 0.5, 2);
	drawSteps();
	glPopMatrix();

	//upper 3 part balcony
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(0, 0.4, -4);
	glScalef(11, 0.5, -2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(0, 0.9, -6);
	glScalef(11, 0.5, -2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(0, 1.4, -8);
	glScalef(11, 0.5, -2);
	glutSolidCube(1);
	glPopMatrix();

	//upper 7 chair set for upper 3 balcony
	glPushMatrix();
	glTranslatef(1.5, 1.5, -4.5);
	drawSet7();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, 2, -6.5);
	drawSet7();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, 2.5, -8.5);
	drawSet7();
	glPopMatrix();

	//single chair at lower 2 step balcony
	glPushMatrix();
	glTranslatef(-4.5, 0.5, -0.5);
	drawChair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, 0.5, -0.5);
	drawChair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.5, 1, -2.5);
	drawChair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, 1, -2.5);
	drawChair();
	glPopMatrix();

	//draw right and left steps
	glPushMatrix();
	glColor3f(0.8, 0, 0.5);
	glTranslatef(6, -0.73, 0.5);
	drawSteps1();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8, 0, 0.5);
	glTranslatef(-6, -0.73, 0.5);
	drawSteps1();
	glPopMatrix();

	//right balcony
	glPushMatrix();
	drawRightBalcony();
	glPopMatrix();

	//left balcony
	glPushMatrix();
	drawLeftBalcony();
	glPopMatrix();

	//front cover
	glPushMatrix();
	drawFrontCovering();
	glPopMatrix();
}