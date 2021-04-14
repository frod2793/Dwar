#include "DXUT.h"
#include "endingscen.h"
#include "Object.h"
#include "titleBotton.h"
#include "Mose.h"
void endingscen::Init()
{
	anytime = new Timer;
	anytime->setTimer(0.3f);
	OBJECT->AddObject("TL", new titleBotton, Vector2(WINSIZEX / 2, WINSIZEY / 9), UI);
	OBJECT->AddObject("Mouse", new Mose, Vector2(100, 100), MOUSE);
}

void endingscen::Update()
{
	if (anytime->Update())
	{


		anime++;
	}
	if (anime >= 7)
	{
		anime = 0;

	}
}

void endingscen::Render()
{
	IMAGE->FindImage("end")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	IMAGE->FINDVECIMAGE("End", 7)->FINDIMAGE(anime)->CenterRender(Vector2(WINSIZEX/2,WINSIZEY/2+300));
}

void endingscen::Release()
{
}
