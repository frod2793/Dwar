#pragma once
#include "singleton.h"
class Math :
	public singleton<Math>
{
public:
	Vector2 RotateVec(Vector2 Vec, float Rot);
	Math();
	virtual ~Math();

	template <typename T>

	void Lerp(T* target, T& start, T& finsh, float time)
	{
		*target = start + (finsh - start) * time* DXUTGetElapsedTime();
	}


};
#define MATH Math::GetInstance()