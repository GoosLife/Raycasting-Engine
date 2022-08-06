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

			xOffset = x * m_cellSize; yOffset = y * m_cellSize;
			glBegin(GL_QUADS);
			glVertex2i(xOffset				+ 1, yOffset			  + 1);
			glVertex2i(xOffset				+ 1, yOffset + m_cellSize - 1);
			glVertex2i(xOffset + m_cellSize - 1, yOffset + m_cellSize - 1);
			glVertex2i(xOffset + m_cellSize - 1, yOffset			  + 1);
			glEnd();
		}
	}
}