#include "DXUT.h"
#include "effect.h"

void effect::Init()
{
	effect = new Timer;
	effect->setTimer(0.03f);
}

void effect::Update()
{
	if (effect->Update())
	{
		effort++;
		if (effort == 5)
		{
			isDestroy = true;
		}
	}
}

void effect::Render()
{
	IMAGE->FINDVECIMAGE("effect", 6)->FINDIMAGE(effort)->CenterRender(vPos,0,Vector2(2.5,2.5));
}

void effect::Release()
{
	SAFE_DELETE(effect);
}

void effect::onCollisionStay(Object* obj)
{
}

void effect::onCollisionExit(Object* obj)
{
}
