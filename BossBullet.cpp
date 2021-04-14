#include "DXUT.h"
#include "BossBullet.h"
#include"cPlayer.h"
#include "BossBullet.h"
#include "endingscen.h"


void BossBullet::Init()
{
	
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(12, 8);
	OBJECT->AddCollision(collider);
	Damege = 1;
	m_image = IMAGE->FindImage("bbt");
}

void BossBullet::Update()
{
	this->collider->SetRange(12, 8);
	vPos += m_dir * 1200*D_TIME ;
	f_checktime += D_TIME;
	if (f_checktime >= f_lifecheck)
		del = true;
}

void BossBullet::Render()
{
	IMAGE->Render(m_image, vPos,0.0f,Vector2(0.5,0.5));
}

void BossBullet::Release()
{
	SAFE_DELETE(collider);
}

void BossBullet::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	

	case PLAYER:
			isDestroy = true;
			Damege = 1;
			SCENE->AddScene("end ", new endingscen);
			
		break;
	}
}

void BossBullet::onCollisionExit(Object* obj)
{
}
