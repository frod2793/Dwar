#include "DXUT.h"
#include "Stage2.h"
#include "IngameScene.h"
#include "TEST.h"
#include "Scrollmap.h"
#include "cPlayer.h"
#include "Bullet.h"
#include "Enemy.h"
#include "trackEn.h"
void Stage2::Init()
{
	m_map = new Scrollmap();
	enemyspawn = new Timer;

	enemyspawn->setTimer(0.5f);
		
	m_map->Init(IMAGE->FindImage("BackGround"));

	srand(time(NULL));
	textTime = 0;

	color =
	{
		255,255,255,255
	};
	OBJECT->AddObject("player", new cPlayer, Vector2(WINSIZEX / 2, WINSIZEY / 2), PLAYER);
}

void Stage2::Update()
{

	if (OBJECT->score >= 20) {
		SCENE->ChangeScene("boss");
	}
	m_map->Update(100);

	spawnPos = rand() % 1600;

	if (enemyspawn->Update())
	{
		OBJECT->AddObject("track", new trackEn, Vector2(spawnPos, -100), ENEMY);
		OBJECT->AddObject("enemy", new Enemy, Vector2(spawnPos, -100), ENEMY);
	}
	textTime += D_TIME;
}

void Stage2::Render()
{
	m_map->Render();
	if (textTime < 2)
	{
		IMAGE->drawText("STAGE 2", Vector2(WINSIZEX / 2, WINSIZEY / 2), 50, color, true);
	}
}

void Stage2::Release()
{
	SAFE_DELETE(m_map);
	SAFE_DELETE(enemyspawn);
}
