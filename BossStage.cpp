#include "DXUT.h"
#include "BossStage.h"
#include "IngameScene.h"
#include "TEST.h"
#include "Scrollmap.h"
#include "cPlayer.h"
#include "Bullet.h"
#include "Enemy.h"
#include"Boss.h"
void BossStage::Init()
{
	m_map = new Scrollmap();
	m_map->Init(IMAGE->FindImage("BackGround"));
	srand(time(NULL));
	textTime = 0;

	color =
	{
		255,255,255,255
	};
	OBJECT->AddObject("boss", new Boss, Vector2(WINSIZEX / 2, 200), BOSS);
	OBJECT->AddObject("player", new cPlayer, Vector2(WINSIZEX / 2, WINSIZEY / 2), PLAYER);
}

void BossStage::Update()
{
	
}

void BossStage::Render()
{
	m_map->Render();
	if (textTime < 2)
	{
		IMAGE->drawText("Boss Stage", Vector2(WINSIZEX / 2, WINSIZEY / 2), 50, color, true);
	}
}

void BossStage::Release()
{
	SAFE_DELETE(m_map);
	//SAFE_DELETE(enemyspawn);
}
