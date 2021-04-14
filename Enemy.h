#pragma once
#include "Object.h"
class Enemy :
	public Object
{
private:
	Vector2 m_En;
	Timer* enemySpawn;
	float e_Checktime;
	float e_spawntime;
public:

	// Object��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void onCollisionStay(Object* obj) override;
	virtual void onCollisionExit(Object* obj) override;
};

