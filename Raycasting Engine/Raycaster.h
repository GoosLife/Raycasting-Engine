#pragma once
#include "Map.h"
#include <math.h>

#define PI 3.1415926535
#define P2 PI/2
#define P3 3*PI/2

class Raycaster
{
public:
	Raycaster(float angle) : m_angle(angle) { m_depthOfField = 0; /* m_ypos = 0; */ };
	void DrawRays3D(float playerAngle, float playerYPos, float playerXPos, int mapWidth, int mapHeight, int* map);
private:
	float m_angle;
	float m_ypos;
	float m_xpos;
	float m_offsetX;
	float m_offsetY;

	//
	int mx;
	int my;
	int mp;

	int m_depthOfField; // How deep the raycaster should search
};

