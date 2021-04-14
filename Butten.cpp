#include "DXUT.h"
#include "Butten.h"

void Butten::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(127, 67);
	OBJECT->AddCollision(collider);

	vPos = Vector2(WINSIZEX / 2, WINSIZEY / 2);
	isCo = false;
}

void Butten::Update()
{
	this->collider->SetRange(127, 67);
}

void Butten::Render()
{
	IMAGE->FindImage("PL")->CenterRender(vPos);
	
	if (isCo)
	{
		IMAGE->FindImage("PL")->CenterRender(vPos,0,Vector2(1.2f,1.2f));	
	}
}

void Butten::Release()
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
	SAFE_DELETE(collider);
}

void Butten::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case MOUSE:
		isCo = true;
		if(INPUT->KeyDown(VK_LBUTTON))
			SCENE->ChangeScene("ingame");
		break;
	}
}

void Butten::onCollisionExit(Object* obj)
{
	isCo = false;
}
