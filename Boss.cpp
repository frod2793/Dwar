#include "DXUT.h"
#include "Boss.h"
#include"cPlayer.h"
#include "BossBullet.h"
#include "Object.h"
void Boss::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	this->collider->SetRange(120, 120);
	OBJECT->AddCollision(collider);
	Hp = 300;
	pattern = 1;
	
	
	anytime = new Timer;
	anytime->setTimer(0.3f);

}

void Boss::Update()
{
	switch (pattern)
	{
	case 0:
		break;
	case 1:
		Pattern1();
		break;
	

	}
	
	

	this->collider->SetRange(120, 120);

	if (anytime->Update())
	{
		float angle = 0;
		float rad = D3DX_PI * 2 / 45;
		for (int i = 0; i < 45; i++, angle += rad)
		{
			Vector2 dir = Vector2(vPos.x + cos(angle) * 5, vPos.y + sin(angle) * 5);
			D3DXVec2Normalize(&dir, &(dir - vPos));
			OBJECT->AddObject("bullet", new BossBullet(dir), vPos, EBULLET);
		}
		anime++;
	}
	if (anime >= 2)
	{
		anime = 0;

	}
}


void Boss::Pattern1()
{

	switch (pattern2)
	{
	case 1:
		m_angle = atan2(400 - 200, (vPos.x - 615) - vPos.x);
		vPos += Vector2(cos(m_angle), sin(m_angle)) * 100*D_TIME;
		if (vPos.y >= 400)
		{
			pattern2++;
			b_bullet = true;
		}
		if (b_bullet)
		{
			float angle = 0;
			float rad = D3DX_PI * 2 / 45;
			for (int i = 0; i < 45; i++, angle += rad)
			{
				Vector2 dir = Vector2(vPos.x + cos(angle) * 5, vPos.y + sin(angle) * 5);
				D3DXVec2Normalize(&dir, &(dir - vPos));
				OBJECT->AddObject("bullet", new BossBullet(dir), vPos, EBULLET);
			}
			b_bullet = false;
		}
		break;
	case 2:
		m_angle = atan2(600 - 400, (vPos.x + 1230) - vPos.x);
		vPos += Vector2(cos(m_angle), sin(m_angle)) * 100*D_TIME;
		if (vPos.y >= 600)
		{
			pattern2++;
			b_bullet = true;
		}
		if (b_bullet)
		{
			float angle = 0;
			float rad = D3DX_PI * 2 / 45;
			for (int i = 0; i < 45; i++, angle += rad)
			{
				Vector2 dir = Vector2(vPos.x + cos(angle) * 5, vPos.y + sin(angle) * 5);
				D3DXVec2Normalize(&dir, &(dir - vPos));
				OBJECT->AddObject("bullet", new BossBullet(dir), Vector2(vPos.x, vPos.y), EBULLET);
			}
			b_bullet = false;
		}
		break;
	case 3:
		m_angle = atan2(800 - 600, (vPos.x - 1230) - vPos.x);
		vPos += Vector2(cos(m_angle), sin(m_angle)) * 1100*D_TIME;
		if (vPos.y >= 800)
		{
			pattern2++;
			b_bullet = true;
		}
		if (b_bullet)
		{
			float angle = 0;
			float rad = D3DX_PI * 2 / 45;
			for (int i = 0; i < 45; i++, angle += rad)
			{
				Vector2 dir = Vector2(vPos.x + cos(angle) * 5, vPos.y + sin(angle) * 5);
				D3DXVec2Normalize(&dir, &(dir - vPos));
				OBJECT->AddObject("bullet", new BossBullet(dir), Vector2(vPos.x, vPos.y), EBULLET);
			}
			b_bullet = false;
		}
		break;
	case 4:
		ready = true;
		
		D3DXVec2Normalize(&Pos, &Vector2( Vector2(800, 200)- vPos));
		vPos += Pos * 300 * D_TIME;
		if (vPos.y < 200)
		{
			pattern2 = 1;
		}
	
		break;
	}
}

void Boss::Render()
{
	IMAGE->FindImage("hp")->Render({ WINSIZEX / 2 , WINSIZEY / 3 }, 0, { Hp / 100,2 });
	IMAGE->FINDVECIMAGE("boss", 2)->FINDIMAGE(anime)->CenterRender(vPos,0,Vector2(0.2,0.2));
	IMAGE->drawText(to_string(vPos.y),Vector2(200,200),50,D3DCOLOR_XRGB(255,255,255),false);
}

void Boss::Release()
{
	SAFE_DELETE(collider);
	SAFE_DELETE(anytime);

}

void Boss::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	

	case BULLET:
		Hp -= obj->Damege;
		if (Hp <= 0)
		{
			isDestroy = true;
			SCENE->ChangeScene("clear");
			
		}
		break;
	}
}

void Boss::onCollisionExit(Object* obj)
{
}
