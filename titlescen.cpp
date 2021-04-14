#include "DXUT.h"
#include "titlescen.h"
#include "titleback.h"
#include "Mose.h"
#include "Butten.h"
#include "Butten2.h"
#include"button3.h"
#include"QUITBottom.h"
title::title()
{
}

title::~title()
{
}

void title::Init()
{

	OBJECT->AddObject("CL",new Butten2 ,Vector2(WINSIZEX / 4, WINSIZEY / 4), UI);
	OBJECT->AddObject("PL", new Butten, Vector2(WINSIZEX / 2, WINSIZEY / 2),UI);
	OBJECT->AddObject("QT", new QUITBottom, Vector2(WINSIZEX / 4, WINSIZEY /2),UI);
	OBJECT->AddObject("OP",new button3 ,Vector2(WINSIZEX / 2, WINSIZEY / 4), UI);
	OBJECT->AddObject("Mouse", new Mose, Vector2(100, 100), MOUSE);


}

void title::Update()
{
}

void title::Render()
{
	IMAGE->drawText("dfdsa",Vector2(500,500),50,D3DCOLOR_XRGB(255,255,255),true);
	IMAGE->FindImage("title")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
}

void title::Release()
{

}
