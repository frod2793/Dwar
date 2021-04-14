#include "DXUT.h"
#include "QUITBottom.h"

void QUITBottom::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(127, 67);
	OBJECT->AddCollision(collider);

	vPos = Vector2(WINSIZEX / 2, WINSIZEY / 4);
	isCo = false;
}

void QUITBottom::Update()
{
	this->collider->SetRange(127, 67);
}

void QUITBottom::Render()
{

	if (isCo)
	{
		IMAGE->FindImage("QT")->CenterRender(vPos, 0, Vector2(1.2f, 1.2f));
	}
	else
	{
		IMAGE->FindImage("QT")->CenterRender(vPos);

	}
}

void QUITBottom::Release()
{
	SAFE_DELETE(collider);
}

void QUITBottom::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case MOUSE:
		isCo = true;
		if (INPUT->KeyDown(VK_LBUTTON))
			exit(1);
		break;
	}
}

void QUITBottom::onCollisionExit(Object* obj)
{
	isCo = false;
}
