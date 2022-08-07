#include "Map.h"

int Map::GetWidth()
{
	return m_width;
}

int Map::GetHeight()
{
	return m_height;
}

int* Map::GetLayout()
{
	return m_mapLayout;
}

int Map::GetCubeSize()
{
	return m_cubeSize;
}

void Map::DrawMap2D()
{
	int x, y, xOffset, yOffset;

	for (y = 0; y < m_height; y++)
	{
		for (x = 0; x < m_width; x++)
		{
			if (m_mapLayout[y * m_width + x] == 1)
			{
				glColor3f(1, 1, 1);
			}
			else
			{
				glColor3f(0, 0, 0);
			}

			switch (m_mapLayout[y * m_width + x])
			{
			case 1:
				glColor3f(1, 0, 0);
				break;
			case 2:
				glColor3f(0, 1, 0);
				break;
			case 3:
				glColor3f(0, 0, 1);
				break;
			}

			xOffset = x * m_cubeSize; yOffset = y * m_cubeSize;
			glBegin(GL_QUADS);
			glVertex2i(xOffset				+ 1, yOffset			  + 1);
			glVertex2i(xOffset				+ 1, yOffset + m_cubeSize - 1);
			glVertex2i(xOffset + m_cubeSize - 1, yOffset + m_cubeSize - 1);
			glVertex2i(xOffset + m_cubeSize - 1, yOffset			  + 1);
			glEnd();
		}
	}
}