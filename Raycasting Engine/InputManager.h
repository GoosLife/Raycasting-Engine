#pragma once

class InputManager
{
public:
	/// <summary>
	/// Holds input button press state (up = 1, down = 0)
	/// </summary>
	struct ButtonKeys
	{
		int w, a, d, s;
	}Keys;

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
	static void ButtonDown(unsigned char  key, int x, int y);
	static void ButtonUp(unsigned char key, int  x, int y);

private:	
	InputManager() { m_pressedKey = 0; }
	static  InputManager* s_pInstance;
	unsigned char m_pressedKey;

};