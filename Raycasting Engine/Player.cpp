#include "Player.h"

float Player::GetX()
{
	return m_xpos;
}

float Player::GetY()
{
	return m_ypos;
}

void Player::SetX(float x)
{
	m_xpos = x;
}

void Player::SetY(float y)
{
	m_ypos = y;
}

void Player::MovePlayer(float x, float y)
{
	m_xpos += x;
	m_ypos += y;
}

void Player::DrawPlayer()
{
	glColor3f(1, 1, 0);
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2i(m_xpos, m_ypos);
	glEnd();
}

void Player::UpdatePlayer()
{
	switch (InputManager::Instance()->GetPressedKey())
	{
	case 'w':
		MovePlayer(0,-5);
		break;
	case 'a':
		MovePlayer(-5,0);
		break;
	case 's':
		MovePlayer(0,5);
		break;
	case 'd':
		MovePlayer(5,0);
		break;
	default:
		break;
	}
}
