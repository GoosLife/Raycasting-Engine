#pragma once
#include <math.h>
#include "GL/glut.h"
#include "InputManager.h"
#include "Raycaster.h"

#define PI 3.1415926535

class Player
{
public:
	Player(float x, float y, float angle) ;

	float GetX();
	void SetX(float x);
	
	float GetY();
	void SetY(float y);
	
	float GetHorizontalDirection();
	void SetHorizontalDirection(float x);
	
	float GetVerticalDirection();
	void SetVerticalDirection(float y);

	float GetAngle();
	void SetAngle(float angle);

	void MovePlayer(float x, float y);
	void RotatePlayer(float angle);

	void DrawPlayer();
	void UpdatePlayer();
private:
	float m_xpos;
	float m_ypos;

	float m_horizontalDirection;
	float m_verticalDirection;

	float m_angle;
};