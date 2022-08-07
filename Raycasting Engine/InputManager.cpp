#include "InputManager.h"
#include <GL/glut.h>

#include <iostream>

InputManager* InputManager::s_pInstance = 0;

void InputManager::GetInput(unsigned char key, int x, int y)
{
	InputManager::Instance()->m_pressedKey = key;
}

bool InputManager::IsKeyPressed(unsigned char key)
{
	std::cout << m_pressedKey;
	return key == m_pressedKey;
}

unsigned char InputManager::GetPressedKey()
{
	return m_pressedKey;
}

void InputManager::ButtonDown(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		Instance()->Keys.w = 1;
		break;
	case 'a':
		Instance()->Keys.a = 1;
		break;
	case 's':
		Instance()->Keys.s = 1;
		break;
	case 'd':
		Instance()->Keys.d = 1;
		break;
	}

	glutPostRedisplay();
}

void InputManager::ButtonUp(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		Instance()->Keys.w = 0;
		break;
	case 'a':
		Instance()->Keys.a = 0;
		break;
	case 's':
		Instance()->Keys.s = 0;
		break;
	case 'd':
		Instance()->Keys.d = 0;
		break;
	}

	glutPostRedisplay();
}
