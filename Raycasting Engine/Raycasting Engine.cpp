#include "InputManager.h"
#include "Map.h"
#include "Player.h"
#include "Raycasting Engine.h"
#include "Raycaster.h"

#include <GL/glut.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>

int* testLevel = new int[]
{
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 1, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
};

Player* p = new Player(300, 300, 0);
Map* m = new Map(8, 8, 64, testLevel);
Raycaster* r = new Raycaster(p->GetAngle());

void init()
{
	glClearColor(0.3, 0.3, 0.3, 0);
	gluOrtho2D(0, 1024, 512, 0);
}

void update(unsigned char key, int x, int y)
{
	// Get input
	InputManager::Instance()->GetInput(key, x, y);

	// Update objects
	p->UpdatePlayer();
	
	// Draw the display again
	glutPostRedisplay();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m->DrawMap2D();
	p->DrawPlayer();
	r->DrawRays3D(p->GetAngle(), p->GetY(), p->GetX(), m->GetWidth(), m->GetHeight(), m->GetLayout());
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1024, 512);
	glutCreateWindow("Raycasting Engine");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(update); // I'm using this to call my update function - there must be a better way.
	glutMainLoop();
}