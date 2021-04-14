#include "DXUT.h"
#include "bossScene.h"
#include "IngameScene.h"
#include "TEST.h"
#include "Scrollmap.h"
#include "cPlayer.h"
#include "Bullet.h"
#include "Enemy.h"
void bossScene::Init()
{
	m_map = new Scrollmap();
	m_map->Init(IMAGE->FindImage("BackGround"));
	srand(time(NULL));
	textTime = 0;

	color =
	{
		255,255,255,255
	};
	OBJECT->AddObject("player", new cPlayer, Vector2(WINSIZEX / 2, WINSIZEY / 2), PLAYER);
}

void bossScene::Update()
{
	m_map->Update(100);
}

void bossScene::Render()
{
	m_map->Render();
	if (textTime < 2)
	{
		IMAGE->drawText("Boss is in coming", Vector2(WINSIZEX / 2, WINSIZEY / 2), 50, color, true);
	}
}

void bossScene::Release()
{
	SAFE_DELETE(m_map);
}
