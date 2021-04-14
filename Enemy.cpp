#include "DXUT.h"
#include "Enemy.h"
#include "Bullet.h"
#include "effect.h"
#include "endingscen.h"
void Enemy::Init()
{
	
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(120, 98);
	OBJECT->AddCollision(collider);
	Hp = 40;
	Damege = 20;
	m_image = IMAGE->FindImage("enemy");
	
}

void Enemy::Update()
{
	this->collider->SetRange(120, 98);
	vPos.y +=100*D_TIME;

}

void Enemy::Render()
{
	IMAGE->FindImage("enemy")->CenterRender(vPos);

	//IMAGE->FINDVECIMAGE("effect", 6)->FINDIMAGE(effort)->CenterRender(vPos);

}

void Enemy::Release()
{
	SAFE_DELETE(collider);
}

void Enemy::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case PLAYER:

		isDestroy = true;
		SCENE->AddScene("end ", new endingscen);
	case BULLET:
		Hp -= obj->Damege;
		if (Hp <= 0)
		{
			isDestroy = true;
			OBJECT->score += 1;
			OBJECT->AddObject("effect", new effect, vPos, EFFECT);
		}
		break;
	}
}

void Enemy::onCollisionExit(Object* obj)
{
	
}
