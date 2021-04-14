#pragma once
#include "Object.h"

class Bullet :
	public Object
{
public:
	VECtexture m_Image;
;
	float f_lifecheck=0;
	float f_checktime=0;

	bool del = false;


	// Object을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void onCollisionStay(Object* obj) override;
	virtual void onCollisionExit(Object* obj) override;
};

