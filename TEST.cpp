#include "DXUT.h"
#include "TEST.h"


TEST::TEST()
{
}


TEST::~TEST()
{
}

void TEST::Init()
{
}

void TEST::Update()
{
}

void TEST::Render()
{
	IMAGE->FindImage("BackGround")->CenterRender(vPos);
}

void TEST::Release()
{
	isDestroy = true;
}

void TEST::onCollisionStay(Object * obj)
{
}

void TEST::onCollisionExit(Object * obj)
{
}
