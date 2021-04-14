#pragma once
#include "Collider.h"

enum ObjectTag : char
{
	NONE,
	EBULLET,
	BULLET,
	PLAYER,
	BOSS,
	ENEMY,
	EFFECT,
	UI,
	MOUSE,
	END,
}typedef Tag;

class Object
{
	friend class cObjectManager;
public:
	Object();
	virtual ~Object();

	Vector2			vPos;
	Collider*		collider;
	Tag				m_Tag;
	texture*		m_image;
	VECtexture* vec_image;
	Vector2 m_vVelocity;
	string m_Key;
	float Hp;
	float Speed;
	float Damege;
	float MaxHp;
	int score = 0;
	bool isDestroy = false;

public:

	virtual void Init()										PURE;
	virtual void Update()									PURE;
	virtual void Render()									PURE;
	virtual void Release()									PURE;
	virtual void onCollisionStay(Object* obj)				PURE;
	virtual void onCollisionExit(Object* obj)				PURE;

	bool CheckDestroy() { return isDestroy; }

};

