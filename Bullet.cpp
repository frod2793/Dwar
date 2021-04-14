#include "DXUT.h"
#include "Bullet.h"
#include "Object.h"
#include "cPlayer.h"
void Bullet::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(12, 8);
	OBJECT->AddCollision(collider);
	Damege = 20;
	m_image = IMAGE->FindImage("bullet");
}

void Bullet::Update()
{
	this->collider->SetRange(12, 8);
	f_checktime += D_TIME;

	vPos +=( Vector2(0, - 1) * 12);

	if (f_checktime >= f_lifecheck)
		del = true;
}

void Bullet::Render()
{

	IMAGE->Render(m_image, vPos);
}

void Bullet::Release()
{
	SAFE_DELETE(collider);
}

void Bullet::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case ENEMY:
		Damege=20;
		isDestroy = true;

	case BOSS:
	
		isDestroy = true;
		break;
	}
}

void Bullet::onCollisionExit(Object* obj)
{
}
