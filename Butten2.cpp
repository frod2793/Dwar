#include "DXUT.h"
#include "Butten2.h"

void Butten2::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(127, 67);
	OBJECT->AddCollision(collider);

	vPos = Vector2(WINSIZEX / 4, WINSIZEY / 3);
	isCo = false;
}

void Butten2::Update()
{
	this->collider->SetRange(127, 67);
}

void Butten2::Render()
{

	if (isCo)
	{
		IMAGE->FindImage("CL")->CenterRender(vPos, 0, Vector2(1.2f, 1.2f));
	}
	else
	{
		IMAGE->FindImage("CL")->CenterRender(vPos);
	}
}

void Butten2::Release()
{
	SAFE_DELETE(collider)
}

void Butten2::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case MOUSE:
		isCo = true;
		if (INPUT->KeyDown(VK_LBUTTON))
			SCENE->ChangeScene("credit");
		break;
	}
}

void Butten2::onCollisionExit(Object* obj)
{
	isCo = false;
}
