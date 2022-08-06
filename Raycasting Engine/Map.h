#pragma once
#include "GL/glut.h"

class Map
{
public:
	Map(int width, int height, int cellSize, int* mapLayout) : m_width(width), m_height(height), m_cellSize(cellSize), m_mapLayout(mapLayout) {};
	void DrawMap2D();

private:
	int m_width;
	int m_height;
	int m_cellSize;
	int* m_mapLayout;
};

