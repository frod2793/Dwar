#include "DXUT.h"
#include "cPlayer.h"
#include "Object.h"
#include "Bullet.h"
#include "Enemy.h"



void cPlayer::shootBullet()
{
	OBJECT->AddObject("bullet", new Bullet, Vector2(WINSIZEX / 2, WINSIZEY / 2), BULLET);
}


cPlayer::cPlayer()
{
}

cPlayer::~cPlayer()
{
	Release();
}

void cPlayer::Init()
{
	dld = new Timer;
	dld->setTimer(0.2f);
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(34, 46);
	OBJECT->AddCollision(collider);
	dead = true;
	vPos = Vector2(WINSIZEX / 2, WINSIZEY / 2);

	Hp = 100;
	 
	
	anytime = new Timer;
	anytime->setTimer(0.3f);

}

void cPlayer::Update()
{
	Movement();

	this->collider->SetRange(34, 46);
	
	if (Hp <= 0)
	{

		isDestroy = true;
		SCENE->ChangeScene("ending");
	}

	if (anytime->Update())
	{

		
			anime++;
	}
	if (anime >= 4)
	{
		anime = 0;

	}
}

void cPlayer::Render()
{
	IMAGE->FindImage("hp")->Render({ WINSIZEX/4 , WINSIZEY /2 }, 0, { Hp / 50, 1});
	IMAGE->FINDVECIMAGE("player", 5)->FINDIMAGE(anime)->CenterRender(vPos);
	if (!top)
	{
		

	}
	else if (top) {
	//IMAGE->FindImage("stop")->CenterRender({ WINSIZEX / 2,WINSIZEY / 2 });

	}
}


void cPlayer::Release()
{
	SAFE_DELETE(collider);
	SAFE_DELETE(anytime);
	SAFE_DELETE(dld);
}

void cPlayer::Movement()

{
	if (INPUT->KeyPress('A') && vPos.x > 0)
	{
		vPos.x -= 700*D_TIME;

	}
	if (DXUTWasKeyPressed('T')&&!stop)
	{
		top = true;
		stop = true;
		OBJECT->TimeScale = 0;

	}
	else if (DXUTWasKeyPressed('T')&&stop)
	{
		top = false;
		stop = false;
		OBJECT->TimeScale = 1;

	}
	if (INPUT->KeyPress('D') && vPos.x < 1600) {
		vPos.x += 700 * D_TIME;
	}
	if (INPUT->KeyPress('W') && vPos.y > 0) {

		vPos.y -= 700 * D_TIME;
	}
	if (INPUT->KeyPress('S') && vPos.y < 900) {
		vPos.y += 700 * D_TIME;
	}

	if (INPUT->KeyPress(VK_SPACE)&& vPos) {
		if(dld->Update())
			OBJECT->AddObject("bullet", new Bullet, Vector2(vPos.x-10 , vPos.y+1), BULLET);
	}
}

void cPlayer::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case EBULLET:
		dead = false;
		Damege = 1;
		Hp -= obj->Damege;
		
		break;

	case ENEMY:
		Hp -= obj->Damege;
		dead =false;
		
		break;
	}
}

void cPlayer::onCollisionExit(Object* obj)
{

	dead = true;
}

