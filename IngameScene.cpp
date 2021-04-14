#include "DXUT.h"
#include "IngameScene.h"
#include "TEST.h"
#include "Scrollmap.h"
#include "cPlayer.h"
#include "Bullet.h"
#include "Enemy.h"
#include "trackEn.h"

IngameScene::IngameScene()
{
}


IngameScene::~IngameScene()
{
}

void IngameScene::Init()
{
	m_map = new Scrollmap();

	enemyspawn = new Timer;

	enemyspawn->setTimer(1.0f);

	m_map->Init(IMAGE->FindImage("BackGround"));

	srand(time(NULL));

	textTime = 0;

	color =
	{
		255,255,255,255
	};

	OBJECT->AddObject("player", new cPlayer, Vector2(WINSIZEX / 2, WINSIZEY / 2), PLAYER);
	//aOBJECT->AddObject("bulet", new Bullet, Vector2(WINSIZEX / 2, WINSIZEY / 2), BULLET);
}

void IngameScene::Update()
{
	
	if(OBJECT->score >= 10) {
		SCENE->ChangeScene("stage2");
	}
	m_map->Update(100);

	spawnPos = rand() % 1600;

	if (enemyspawn->Update())
	{
		OBJECT->AddObject("enemy", new Enemy, Vector2(spawnPos,-100),ENEMY);
		OBJECT->AddObject("track", new trackEn, Vector2(spawnPos, -100),ENEMY);
	}
	textTime += D_TIME;
}

void IngameScene::Render()
{
	
	m_map->Render();
	if (textTime < 2)
	{
		IMAGE->drawText("STAGE 1", Vector2(WINSIZEX / 2, WINSIZEY / 2), 50, color, true);
	}
}

void IngameScene::Release()
{
	SAFE_DELETE(m_map);
	SAFE_DELETE(enemyspawn);
}
