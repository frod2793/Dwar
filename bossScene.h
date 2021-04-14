#pragma once
#include "Scene.h"
class Scrollmap;
class bossScene :
	public Scene
{
private:

	Scrollmap* m_map;
	D3DXCOLOR color;
	float textTime;
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

