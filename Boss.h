#pragma once
#include "Object.h"
class cPlayer;
class Boss :
	public Object
{
private:
	Vector2 Pos;
	bool ready = false;
	cPlayer* m_player;
	int pattern = 0;
	float m_angle;
	bool b_bullet = false;
	bool pattern1 = 0;
	int pattern2 = 1;
	bool pattern3 = 0;
	
	Timer* bullet_delay;
	Vector2 m_Bn;
	Timer* enemySpawn;
	float e_Checktime;
	float e_spawntime;
	Timer* anytime;
	int anime = 0;
	int a = 0;
	float rad = 0;
	// Object을(를) 통해 상속됨
	void Pattern1();
	void Pattern2();
	void Pattern3();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void onCollisionStay(Object* obj) override;
	virtual void onCollisionExit(Object* obj) override;
};

