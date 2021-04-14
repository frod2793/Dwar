#include "DXUT.h"
#include "clear.h"
#include "Mose.h"
#include "titleBotton.h"
#include "Object.h"
void clear::Init()
{
	anytime = new Timer;
	anytime->setTimer(0.3f);
	OBJECT->AddObject("TL", new titleBotton, Vector2(WINSIZEX / 2, WINSIZEY / 9), UI);
	OBJECT->AddObject("Mouse", new Mose, Vector2(100, 100), MOUSE);
}

void clear::Update()
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

void clear::Render()
{
	IMAGE->FindImage("clear")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	IMAGE->FINDVECIMAGE("End", 7)->FINDIMAGE(anime)->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2 + 300));
}

void clear::Release()
{
}
