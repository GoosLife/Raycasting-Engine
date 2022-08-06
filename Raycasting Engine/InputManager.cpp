#include "InputManager.h"
#include <iostream>

InputManager* InputManager::s_pInstance = 0;

void InputManager::GetInput(unsigned char key, int x, int y)
{
	InputManager::Instance()->m_pressedKey = key;
}

bool InputManager::IsKeyPressed(unsigned char key)
{
	return key == m_pressedKey;
}

unsigned char InputManager::GetPressedKey()
{
	return m_pressedKey;
}