#include "DXUT.h"
#include "CreditScene.h"
#include "Scrollmap.h"
void CreditScene::Init()
{
	m_map = new Scrollmap();
	m_map->Init(IMAGE->FindImage("BackGround"));
}

void CreditScene::Update()
{
	m_map->Update(100);
}

void CreditScene::Render()
{
	m_map->Render();
}

void CreditScene::Release()
{
	SAFE_DELETE(m_map);
}
