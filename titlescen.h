#pragma once
#include "Scene.h"
class title :
	public Scene
{
public:
	title();
	virtual ~title();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

