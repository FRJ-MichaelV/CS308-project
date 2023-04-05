#include<stdio.h>
#include <stdlib.h>    
#include<GL/glut.h>
#include<iostream>
#include "Chair.h"
#include "ChairGroup.h"

void drawSet7() {
	glPushMatrix();
	drawChair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, 0, 0);
	drawChair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3, 0, 0);
	drawChair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.5, 0, 0);
	drawChair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6, 0, 0);
	drawChair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, 0, 0);
	drawChair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3, 0, 0);
	drawChair();
	glPopMatrix();
}

void drawSet6() {
	glPushMatrix();
	drawChair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, 0, 0);
	drawChair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3, 0, 0);
	drawChair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.5, 0, 0);
	drawChair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6, 0, 0);
	drawChair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, 0, 0);
	drawChair();
	glPopMatrix();
}

void drawSet3() {
	glPushMatrix();
	drawChair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, 0, 0);
	drawChair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3, 0, 0);
	drawChair();
	glPopMatrix();
}

void drawChairGroup() {
	for (int i = 0; i >= -8; i -= 2) {
		glPushMatrix();
		glTranslatef(0, 0, i);
		drawSet6();
		glPopMatrix();
	}
}