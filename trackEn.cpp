#include "DXUT.h"
#include "trackEn.h"
#include "Bullet.h"
#include "effect.h"

void trackEn::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(120, 98);
	OBJECT->AddCollision(collider);
	Hp = 40;
	Damege = 20;
	m_image = IMAGE->FindImage("enemy");
	player = OBJECT->FindObject("player");
	pPos = player->vPos;
	speed = 2;
}

void trackEn::Update()
{
	this->collider->SetRange(120, 98);
	pPos = player->vPos;
	if (vPos.x < pPos.x)  vPos.x += speed * 100 * D_TIME;
	else if (vPos.x > pPos.x)  vPos.x -= speed * 100 * D_TIME;
	if (vPos.y < pPos.y)  vPos.y += speed * 100 * D_TIME;
	else if (vPos.y > pPos.y)  vPos.y -= speed * 100 * D_TIME;
	
}

void trackEn::Render()
{
	IMAGE->FindImage("TE")->CenterRender(vPos,0,Vector2(0.5,0.5));
}

void trackEn::Release()
{
	SAFE_DELETE(collider);

}

void trackEn::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case PLAYER:

		isDestroy = true;
		
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

void trackEn::onCollisionExit(Object* obj)
{
}
