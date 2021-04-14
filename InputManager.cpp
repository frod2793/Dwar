#include "DXUT.h"
#include "InputManager.h"


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

bool InputManager::MouseLPress()
{
	return (NowMouse[0] == true && OldMouse[0] == true);
}

bool InputManager::MouseLUp()
{
	return (NowMouse[0] == false && OldMouse[0] == true);
}

bool InputManager::MouseLDown()
{
	return (NowMouse[0] == true && OldMouse[0] == false);
}

bool InputManager::MouseRPress()
{
	return (NowMouse[1] == true && OldMouse[1] == true);
}

bool InputManager::MouseRUp()
{
	return (NowMouse[1] == false && OldMouse[1] == true);
}

bool InputManager::MouseRDown()
{

	return (NowMouse[1] == true && OldMouse[1] == false);
}


void InputManager::Update()
{
	memcpy(Last, Current, sizeof(Current));
	for (int i = 0; i < 256; i++)
	{
		Current[i] = false;
		if (GetAsyncKeyState(i))
		{
			Current[i] = true;
		}
	}
}

bool InputManager::KeyDown(BYTE Key)
{
	return Current[Key] && !Last[Key];
}

bool InputManager::KeyUp(BYTE Key)
{
	return !Current[Key] && Last[Key];
}

bool InputManager::KeyPress(BYTE Key)
{
	return Current[Key] && Last[Key];
}
