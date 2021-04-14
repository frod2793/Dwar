#include "DXUT.h"
#include "titleback.h"

titleback::titleback()
{
}

titleback::~titleback()
{
}

void titleback::Init()
{
}

void titleback::Update()
{
}

void titleback::Render()
{
	IMAGE->FindImage("title")->CenterRender(vPos);
}


void titleback::Release()
{
}

void titleback::onCollisionStay(Object* obj)
{
}

void titleback::onCollisionExit(Object* obj)
{
}
