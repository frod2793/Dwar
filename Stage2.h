#pragma once
#include "Scene.h"
class Scrollmap;
class cPlayer;
class Stage2 :
	public Scene
{
private:
	Scrollmap* m_map;
	cPlayer* m_player;
	Timer* enemyspawn;
	float spawnPos;
	D3DXCOLOR color;
	float textTime;
public:
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

