#include "DXUT.h"
#include "button3.h"
#include "titleBotton.h"
#include "Mose.h"
void button3::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(127, 67);
	OBJECT->AddCollision(collider);

	vPos = Vector2(WINSIZEX / 2, WINSIZEY / 4);
	isCo = false;
}

void button3::Update()
{
	this->collider->SetRange(127, 67);
}

void button3::Render()
{
	

	if (isCo)
	{
		IMAGE->FindImage("OP")->CenterRender(vPos, 0, Vector2(1.2f, 1.2f));
	}
	else
	{
		IMAGE->FindImage("OP")->CenterRender(vPos);


	}
	if (!top)
	{
		

	}
	else if (top) {
		OBJECT->AddObject("TL", new titleBotton, Vector2(WINSIZEX / 2, WINSIZEY / 9), UI);
		OBJECT->AddObject("Mouse", new Mose, Vector2(100, 100), MOUSE);
		IMAGE->FindImage("OPP")->CenterRender({ WINSIZEX / 2,WINSIZEY / 2 });
	}
}

void button3::Release()
{
	SAFE_DELETE(collider);
}

void button3::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case MOUSE:
		isCo = true;
		if (INPUT->KeyDown(VK_LBUTTON)) {
			if (!top)
			{
				top = true;

			}
			else if (top) {
				top = false;
			}

			break;
		}
	}
}

void button3::onCollisionExit(Object* obj)
{
	isCo = false;
}
