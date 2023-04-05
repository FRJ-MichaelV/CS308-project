#include<stdio.h>
#include <stdlib.h>    
#include<GL/glut.h>
#include<iostream>
#include "ChairGroup.h"
#include "BottomLayer.h"

void drawFloor() {
	glPushMatrix();
	glColor3f(1, 1, 0.8);
	glScalef(10, 0.01, 10);
	glutSolidCube(1);
	glPopMatrix();
}

void drawLayer1() {
	glPushMatrix();
	glTranslatef(2.4, 0, 12);
	drawChairGroup();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(14, 0, 12);
	drawChairGroup();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-9.5, 0, 12);
	drawChairGroup();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.15, -1, 8.5);
	drawFloor();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(11.75, -1, 8.5);
	drawFloor();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-11.75, -1, 8.5);
	drawFloor();
	glPopMatrix();
}
