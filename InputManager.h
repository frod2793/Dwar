#pragma once
#include "singleton.h"
class InputManager : public singleton <InputManager>
{
private:
	bool NowMouse[2];
	bool OldMouse[2];

	bool NowInput[256];
	bool OldInput[256];
public:
	InputManager();
	virtual ~InputManager();

	bool MouseLPress();
	bool MouseLUp();
	bool MouseLDown();

	bool MouseRPress();
	bool MouseRUp();
	bool MouseRDown();

	void Update();
	
	bool Current[256];
	bool Last[256];
	bool KeyDown(BYTE Key);
	bool KeyUp(BYTE Key);
	bool KeyPress(BYTE Key);

	Vector2 GetMousePos() {
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(DXUTGetHWND(), &pt);

		return Vector2((float)pt.x, (float)pt.y);
	}

	Vector2 GetScrollPos() {
		Vector2 MousePos = GetMousePos();
		//Vector2 ScrollPos = MousePos - Vector2(CAMERA->GetScrollPos().x, CAMERA->GetScrollPos().y);

		//return ScrollPos;
	}

};

#define INPUT InputManager::GetInstance()

