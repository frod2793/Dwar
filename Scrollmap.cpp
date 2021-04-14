#include "DXUT.h"
#include "Scrollmap.h"
#include "Object.h"





Scrollmap::Scrollmap()
	:m_scroll(0)
{
}

Scrollmap::~Scrollmap()
{
}

void Scrollmap::Init(texture* Backgrund)
{ 
	m_image = Backgrund;
}

void Scrollmap::Update(float speed)
{
	m_scroll += speed * D_TIME;
}



void Scrollmap::Render()
{
	float renderPos = (int)m_scroll % m_image->info.Height;
	IMAGE->Render(m_image, Vector2(0, renderPos - m_image->info.Height), 0);
	IMAGE->Render(m_image, Vector2(0, renderPos), 0);
}

void Scrollmap::Release()
{
	//SAFE_DELETE();
}


