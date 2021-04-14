#pragma once
#include "Scene.h"
class clear :
	public Scene
{
	Timer* anytime;
	int anime = 0;
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

