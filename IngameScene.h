#pragma once
#include "Scene.h"
class Scrollmap;
class cPlayer;
class IngameScene :
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
	IngameScene();
	virtual ~IngameScene();

	virtual void Init()		override;
	virtual void Update()	override;
	virtual void Render()	override;
	virtual void Release()	override;
};