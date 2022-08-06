#pragma once
class InputManager
{
public:
	static InputManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

	static void GetInput(unsigned char key, int x, int y);
	bool IsKeyPressed(unsigned char key);
	unsigned char GetPressedKey();

private:	
	InputManager() { m_pressedKey = 0; }
	static  InputManager* s_pInstance;
	unsigned char m_pressedKey;
};