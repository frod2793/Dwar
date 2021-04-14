#include "DXUT.h"
#include "titleBotton.h"

void titleBotton::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(127, 67);
	OBJECT->AddCollision(collider);

	vPos = Vector2(WINSIZEX / 2, WINSIZEY / 4);
	isCo = false;
}

void titleBotton::Update()
{
	this->collider->SetRange(127, 67);
}

void titleBotton::Render()
{
	IMAGE->FindImage("TL")->CenterRender(vPos);

	if (isCo)
	{
		IMAGE->FindImage("TL")->CenterRender(vPos, 0, Vector2(1.2f, 1.2f));
	}
}

void titleBotton::Release()
{
	SAFE_DELETE(collider);
}

void titleBotton::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case MOUSE:
		isCo = true;
		if (INPUT->KeyDown(VK_LBUTTON))
			SCENE->ChangeScene("title");
		break;
	}
}

void titleBotton::onCollisionExit(Object* obj)
{
	isCo = false;
}
