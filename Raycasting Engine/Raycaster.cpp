#include "Raycaster.h"

void Raycaster::DrawRays3D(float playerAngle, float playerYPos, float playerXPos, int mapWidth, int mapHeight, int* map)
{
	m_angle = playerAngle - DR * 30;
	
	if (m_angle < 0)
	{
		m_angle += 2 * PI;
	}

	if (m_angle > 2 * PI)
	{
		m_angle -= 2 * PI;
	}

	// map = new int[mapWidth * mapHeight];

	for (int i = 0; i < 60; i++)
	{
		//// Check horizontal lines
		m_depthOfField = 0;

		float horizontalDistance = 100000;
		float horizontalRayX = playerXPos;
		float horizontalRayY = playerYPos;

		float aTan = -1 / tan(m_angle);

		if (m_angle > PI) { m_ypos = (((int)playerYPos >> 6) << 6) - 0.0001; m_xpos = (playerYPos - m_ypos) * aTan + playerXPos; m_offsetY = -64; m_offsetX = -m_offsetY * aTan; } // Looking down
		if (m_angle < PI) { m_ypos = (((int)playerYPos >> 6) << 6) + 64;     m_xpos = (playerYPos - m_ypos) * aTan + playerXPos; m_offsetY = 64;  m_offsetX = -m_offsetY * aTan; } // Looking up
	
		if (m_angle == 0 || m_angle == PI) { m_xpos = playerXPos; m_ypos = playerYPos; m_depthOfField = 8; } // Looking straight left or right

		while (m_depthOfField < 8)
		{
			mx = (int)(m_xpos) >> 6; my = (int)(m_ypos) >> 6; mp = my * mapWidth + mx;
			if (mp > 0 && mp < mapWidth * mapHeight && map[mp] == 1)
			{
				horizontalRayX = m_xpos;
				horizontalRayY = m_ypos;
				horizontalDistance = Distance(playerXPos, playerYPos, horizontalRayX, horizontalRayY);
				m_depthOfField = 8;
			}
			else
			{
				m_xpos += m_offsetX;
				m_ypos += m_offsetY;
				m_depthOfField++;
			}
		}

		// Check vertical lines
		m_depthOfField = 0;

		float verticalDistance = 100000;
		float verticalRayX = playerXPos;
		float verticalRayY = playerYPos;

		float nTan = -tan(m_angle);

		if (m_angle > P2 && m_angle < P3) { m_xpos = (((int)playerXPos >> 6) << 6) - 0.0001; m_ypos = (playerXPos - m_xpos) * nTan + playerYPos; m_offsetX = -64; m_offsetY = -m_offsetX * nTan; } // Looking left
		if (m_angle < P2 || m_angle > P3) { m_xpos = (((int)playerXPos >> 6) << 6) + 64;     m_ypos = (playerXPos - m_xpos) * nTan + playerYPos; m_offsetX = 64;  m_offsetY = -m_offsetX * nTan; } // Looking right

		if (m_angle == 0 || m_angle == PI) { m_xpos = playerXPos; m_ypos = playerYPos; m_depthOfField = 8; } // Looking straight up or  down

		while (m_depthOfField < 8)
		{
			mx = (int)(m_xpos) >> 6; my = (int)(m_ypos) >> 6; mp = my * mapWidth + mx;
			if (mp > 0 && mp < mapWidth * mapHeight && map[mp] == 1)
			{
				verticalRayX = m_xpos;
				verticalRayY = m_ypos;
				verticalDistance = Distance(playerXPos, playerYPos, verticalRayX, verticalRayY);
				m_depthOfField = 8;
			}
			else
			{
				m_xpos += m_offsetX;
				m_ypos += m_offsetY;
				m_depthOfField++;
			}
		}

		if (horizontalDistance > verticalDistance)
		{
			m_xpos = verticalRayX;
			m_ypos = verticalRayY;
		}
		else
		{
			m_xpos = horizontalRayX;
			m_ypos = horizontalRayY;
		}

		// Draw ray
		glColor3f(1, 0, 0);
		glLineWidth(3);
		glBegin(GL_LINES);
		glVertex2i(playerXPos, playerYPos);
		glVertex2i(m_xpos, m_ypos);
		glEnd();

		m_angle += DR; // Next ray is one degree from this one

		if (m_angle < 0)
		{
			m_angle += 2 * PI;
		}

		if (m_angle > 2 * PI)
		{
			m_angle -= 2 * PI;
		}
	}
}

float Raycaster::Distance(float playerX,  float  playerY, float rayX, float rayY)
{
	return (sqrt((m_xpos-playerX) * (m_xpos-playerX)  +  (m_ypos-playerY)*(m_ypos-playerY)));
}
