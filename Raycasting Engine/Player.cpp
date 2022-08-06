#include "Player.h"

Player::Player(float x, float y, float angle) : m_xpos(x), m_ypos(y), m_angle(angle)
{
	m_horizontalDirection = cos(m_angle) * 5;
	m_verticalDirection = sin(m_angle) * 5;
}

float Player::GetX()
{
	return m_xpos;
}

float Player::GetY()
{
	return m_ypos;
}

float Player::GetHorizontalDirection()
{
	return m_horizontalDirection;
}

float Player::GetVerticalDirection()
{
	return m_verticalDirection;
}

void Player::SetHorizontalDirection(float x)
{
	m_horizontalDirection = x;
}

void Player::SetVerticalDirection(float y)
{
	m_verticalDirection = y;
}

float Player::GetAngle()
{
	return m_angle;
}

void Player::SetAngle(float angle)
{
	m_angle = angle;
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

void Player::RotatePlayer(float angle)
{
	m_angle += angle;

	if (m_angle < 0)
	{
		m_angle += 2 * PI;
	}
	else if (m_angle > 2 * PI)
	{
		m_angle -= 2 * PI;
	}

	m_horizontalDirection = cos(m_angle) * 5;
	m_verticalDirection = sin(m_angle) * 5;
}

void Player::DrawPlayer()
{
	glColor3f(1, 1, 0);
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2i(m_xpos, m_ypos);
	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2i(m_xpos, m_ypos);
	glVertex2i(m_xpos + m_horizontalDirection * 5, m_ypos + m_verticalDirection * 5);
	glEnd();
}

void Player::UpdatePlayer()
{
	switch (InputManager::Instance()->GetPressedKey())
	{
	case 'w':
		MovePlayer(m_horizontalDirection,m_verticalDirection);
		break;
	case 'a':
		RotatePlayer(-0.1);
		break;
	case 's':
		MovePlayer(-m_horizontalDirection,-m_verticalDirection);
		break;
	case 'd':
		RotatePlayer(+0.1);
		break;
	default:
		break;
	}
}
