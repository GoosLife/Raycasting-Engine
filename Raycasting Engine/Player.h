#pragma once
#include "GL/glut.h"
#include "InputManager.h"
class Player
{
public:
	Player(float x, float y) : m_xpos(x), m_ypos(y) {};

	float GetX();
	float GetY();
	void SetX(float x);
	void SetY(float y);

	void MovePlayer(float x, float y);

	void DrawPlayer();
	void UpdatePlayer();
private:
	float m_xpos;
	float m_ypos;
};