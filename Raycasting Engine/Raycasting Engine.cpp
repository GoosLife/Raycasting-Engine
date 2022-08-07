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
	1, 0, 1, 2, 2, 0, 0, 1,
	1, 0, 3, 0, 0, 0, 0, 1,
	1, 0, 3, 0, 0, 1, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
};

Player* p = new Player(300, 300, 0);
Map* m = new Map(8, 8, 64, testLevel);
Raycaster* r = new Raycaster(p->GetAngle());

void Init()
{
	glClearColor(0.3, 0.3, 0.3, 0);
	gluOrtho2D(0, 1024, 512, 0);
}

/// <summary>
/// Update game objects
/// </summary>
/// <param name="key"></param>
/// <param name="x"></param>
/// <param name="y"></param>
void Update()
{
	// Update objects
	p->UpdatePlayer();

	// Draw the display again
	glutPostRedisplay();
}

/// <summary>
/// Draw the game
/// </summary>
void DrawGame()
{
	// Draw game
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m->DrawMap2D();
	p->DrawPlayer();
	r->Draw3DView(p->GetAngle(), p->GetY(), p->GetX(), m->GetWidth(), m->GetHeight(), m->GetLayout(), m->GetCubeSize());
	glutSwapBuffers();
}

void Run()
{
	Update();
	DrawGame();
}

void ResizeWindow(int w, int h)
{
	glutReshapeWindow(1024, 512);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1024, 512);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Raycasting Engine");
	Init();
	glutDisplayFunc(Run);
	glutReshapeFunc(ResizeWindow);
	glutKeyboardFunc(InputManager::Instance()->ButtonDown); // I'm using this to call my update function - there must be a better way.
	glutKeyboardUpFunc(InputManager::Instance()->ButtonUp);
	glutMainLoop();
}