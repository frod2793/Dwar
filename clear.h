#pragma once
#include "Scene.h"
class clear :
	public Scene
{
	Timer* anytime;
	int anime = 0;
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

