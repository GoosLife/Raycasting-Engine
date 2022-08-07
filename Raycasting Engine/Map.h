#pragma once
#include "GL/glut.h"

class Map
{
public:
	Map(int width, int height, int cellSize, int* mapLayout) : m_width(width), m_height(height), m_cubeSize(cellSize), m_mapLayout(mapLayout) {};

	int GetWidth();
	int GetHeight();
	int* GetLayout();
	int GetCubeSize();

	void DrawMap2D();

private:
	int m_width;
	int m_height;
	int m_cubeSize;
	int* m_mapLayout;
};

