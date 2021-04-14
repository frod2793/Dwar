#include "DXUT.h"
#include "MainGame.h"
#include "IngameScene.h"
#include "titlescen.h"
#include "endingscen.h"
#include "Stage2.h"
#include "BossStage.h"
#include "CreditScene.h"
#include "clear.h"
MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	Release();
	

}

void MainGame::Init()
{
	CAMERA->Reset();

	SCENE->AddScene("credit", new CreditScene);
	SCENE->AddScene("boss", new BossStage);
	SCENE->AddScene("title", new title );
	SCENE->AddScene("ingame", new IngameScene);
	SCENE->AddScene("ending", new endingscen);
	SCENE->AddScene("stage2", new Stage2);
	SCENE->AddScene("clear", new clear);

	SCENE->ChangeScene("title");
}

void MainGame::Release()
{
	ImageManager::ReleaseInstance();
	SceneManager::ReleaseInstance();
	InputManager::ReleaseInstance();
	CameraManager::ReleaseInstance();
	Math::ReleaseInstance();
	ObjectManager::ReleaseInstance();
	Timer::ReleaseInstance();
}

void MainGame::Update()
{
	CAMERA->Update();
	SCENE->Update();
	OBJECT->Update();
	INPUT->Update();
}

void MainGame::Render()
{
	CAMERA->SetTransform();
	IMAGE->Begin();

	SCENE->Render();
	OBJECT->Render();

	IMAGE->End();
}

void MainGame::LostDevice()
{
	IMAGE->LostDevice();
}

void MainGame::ResetDevice()
{
	IMAGE->ResetDevice();
}
