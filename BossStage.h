#pragma once
#include "Scene.h"
class Scrollmap;
class cPlayer;
class BossStage :
	public Scene
{
private:
	Scrollmap* m_map;
	cPlayer* m_player;
	Timer* enemyspawn;
	D3DXCOLOR color;

	float spawnPos;
	float textTime;
public:

	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

