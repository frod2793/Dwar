#pragma once
#include "Object.h"
#include "cPlayer.h"
class trackEn :
	public Object
{
private:
	Object* player;
	Vector2 pPos;
	float speed;
	// Object을(를) 통해 상속됨
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void onCollisionStay(Object* obj) override;
	virtual void onCollisionExit(Object* obj) override;
};

